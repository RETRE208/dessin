#include "texture.h"


Texture::Texture()
{
}

Texture::~Texture()
{
}

void Texture::setup()
{
	ofSetFrameRate(0);
	ofSetBackgroundColor(0);

	// dimensions de l'image source
	image_width = image_source.getWidth();
	image_height = image_source.getHeight();

	// initialiser l'image de destination
	image_destination.allocate(image_width, image_height, OF_IMAGE_COLOR);

	// sélectionner le filtre de convolution par défaut
	kernel_type = ConvolutionKernel::identity;
	kernel_name = "identity";
}

// fonction de filtrage par convolution
void Texture::filter(ofImage* image)
{
	// dimensions de l'image source
	image_width = image->getWidth();
	image_height = image->getHeight();

	// résolution du kernel de convolution
	const int kernel_size = 3;

	// décalage à partir du centre du kernel
	const int kernel_offset = kernel_size / 2;

	// nombre de composantes de couleur (RGB)
	const int color_component_count = 3;

	// indices de l'image
	int x, y;

	// indices du kernel
	int i, j;

	// index des composantes de couleur
	int c;

	// index du pixel de l'image source utilisé pour le filtrage
	int pixel_index_img_src;

	// index du pixel de l'image de destination en cours de filtrage
	int pixel_index_img_dst;

	// index du pixel de l'image de destination en cours de filtrage
	int kernel_index;

	// valeur à un des indices du kernel de convolution
	float kernel_value;

	// extraire les pixels de l'image source
	ofPixels pixel_array_src = image->getPixels();

	// extraire les pixels de l'image de destination
	ofPixels pixel_array_dst = image->getPixels();

	// couleur du pixel lu dans l'image source
	ofColor pixel_color_src;

	// couleur du pixel à écrire dans l'image de destination
	ofColor pixel_color_dst;

	// somme du kernel appliquée à chaque composante de couleur d'un pixel
	float sum[color_component_count];

	// itération sur les rangées des pixels de l'image source
	for (y = 1; y < image_height - 1; ++y)
	{
		// itération sur les colonnes des pixels de l'image source
		for (x = 1; x < image_width - 1; ++x)
		{
			// initialiser le tableau où les valeurs de filtrage sont accumulées
			for (c = 0; c < color_component_count; ++c)
				sum[c] = 0;

			// déterminer l'index du pixel de l'image de destination
			pixel_index_img_dst = (image_width * y + x) * color_component_count;

			// itération sur les colonnes du kernel de convolution
			for (j = -kernel_offset; j <= kernel_offset; ++j)
			{
				// itération sur les rangées du kernel de convolution
				for (i = -kernel_offset; i <= kernel_offset; ++i)
				{
					// déterminer l'index du pixel de l'image source à lire
					pixel_index_img_src = (image_width * (y - j) + (x - i)) * color_component_count;

					// lire la couleur du pixel de l'image source
					pixel_color_src = pixel_array_src.getColor(pixel_index_img_src);

					// déterminer l'indice du facteur à lire dans le kernel de convolution
					kernel_index = kernel_size * (j + kernel_offset) + (i + kernel_offset);

					// extraction de la valeur à cet index du kernel
					switch (kernel_type)
					{
					case ConvolutionKernel::identity:
						kernel_value = convolution_kernel_identity.at(kernel_index);
						break;

					case ConvolutionKernel::emboss:
						kernel_value = convolution_kernel_emboss.at(kernel_index);
						break;

					case ConvolutionKernel::sharpen:
						kernel_value = convolution_kernel_sharpen.at(kernel_index);
						break;

					case ConvolutionKernel::edge_detect:
						kernel_value = convolution_kernel_edge_detect.at(kernel_index);
						break;

					case ConvolutionKernel::blur:
						kernel_value = convolution_kernel_blur.at(kernel_index);
						break;

					default:
						kernel_value = convolution_kernel_identity.at(kernel_index);
						break;
					}

					// itération sur les composantes de couleur
					for (c = 0; c < color_component_count; ++c)
					{
						// accumuler les valeurs de filtrage en fonction du kernel de convolution
						sum[c] = sum[c] + kernel_value * pixel_color_src[c];
					}
				}
			}

			// déterminer la couleur du pixel à partir des valeurs de filtrage accumulées pour chaque composante
			for (c = 0; c < color_component_count; ++c)
			{
				// conversion vers entier et validation des bornes de l'espace de couleur
				pixel_color_dst[c] = (int)ofClamp(sum[c], 0, 255);
			}

			// écrire la couleur à l'index du pixel en cours de filtrage
			pixel_array_dst.setColor(pixel_index_img_dst, pixel_color_dst);
		}
	}

	// écrire les pixels dans l'image de destination
	image->setFromPixels(pixel_array_dst);

	ofLog() << "<convolution filter done>";
}