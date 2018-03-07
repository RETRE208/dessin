#include "files.h"
#include "iostream"
#include <windows.h>
#include <shobjidl.h>

class myexception : public exception
{
	virtual const char* what() const throw()
	{
		return "The user canceled the Choose File Window";
	}
} CANCEL_ERROR;

string Files::getFile() {
	COMDLG_FILTERSPEC aFileTypes[] = {
		{ L"Images", L"*.jpg;*.jpeg;*.png" },
		{ L"3D model", L"*.obj" }
	};

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	char path[128];

	if (SUCCEEDED(hr))
	{
		IFileOpenDialog *pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
		hr = pFileOpen->SetFileTypes(_countof(aFileTypes), aFileTypes);

		if (SUCCEEDED(hr))
		{
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem *pItem;
				hr = pFileOpen->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					
					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						wcstombs(path, pszFilePath, 128);
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			else {
				throw CANCEL_ERROR;
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	return std::string(path);
}