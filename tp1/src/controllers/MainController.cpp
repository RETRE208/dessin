#include "MainController.h"

void MainController::setup()
{
	primitivePanel.setup();
	mainPanel.setup(this);
}

void MainController::draw()
{
	mainPanel.draw();
	primitivePanel.draw();

	for (int i = 0; i < images.size(); i++) {
		int imageWidth = images[i]->getWidth();
		int imageHeight = images[i]->getHeight();

		images[i]->draw(
			DRAWING_ZONE_X_LIMIT,
			DRAWING_ZONE_Y_LIMIT,
			imageWidth,
			imageHeight);
	}
}

void MainController::exportImage() {
	ofImage image;
	string time_stamp = ofGetTimestampString("_%y%m%d-%H%M%S-%i");
	string file_name = "image" + time_stamp + ".png";

	image.grabScreen(DRAWING_ZONE_X_LIMIT, DRAWING_ZONE_Y_LIMIT, DRAWING_ZONE_WIDTH, DRAWING_ZONE_HEIGHT);

	image.save(file_name);

	ofLog() << "<export image: " << file_name << ">";
}

void MainController::importImage() {
	try {
		string imagePath = files.getFile();
		ofImage *newImage = new ofImage;
		newImage->load(imagePath);
		images.push_back(newImage);
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}

void MainController::applyTexture(int keyPressed) {
	switch (keyPressed)
	{
	case 49:  // key 1
		texture.kernel_type = ConvolutionKernel::identity;
		texture.kernel_name = "identité";

		break;

	case 50:  // key 2
		texture.kernel_type = ConvolutionKernel::emboss;
		texture.kernel_name = "bosseler";

		break;

	case 51:  // key 3
		texture.kernel_type = ConvolutionKernel::sharpen;
		texture.kernel_name = "aiguiser";
		break;

	case 52:  // key 4
		texture.kernel_type = ConvolutionKernel::edge_detect;
		texture.kernel_name = "détection de bordure";
		break;

	case 53:  // key 5
		texture.kernel_type = ConvolutionKernel::blur;
		texture.kernel_name = "flou";
		break;

	default:
		break;
	}
	texture.filter(images[0]);
}
	