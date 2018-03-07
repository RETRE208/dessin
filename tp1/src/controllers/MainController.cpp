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
		int imageWidth = images[i].getWidth();
		int imageHeight = images[i].getHeight();

		images[i].draw(
			DRAWING_ZONE_X_LIMIT,
			DRAWING_ZONE_Y_LIMIT,
			imageWidth,
			imageHeight);
	}
}

void MainController::exportImage() {
	try {
		ofImage image;
		string fileName = files.setFile() + ".png";

		image.grabScreen(DRAWING_ZONE_X_LIMIT, DRAWING_ZONE_Y_LIMIT, DRAWING_ZONE_WIDTH, DRAWING_ZONE_HEIGHT);

		image.save(fileName);

		ofLog() << "<export image: " << fileName << ">";
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}

void MainController::importImage() {
	try {
		string imagePath = files.getFile();
		ofImage newImage;
		newImage.load(imagePath);
		images.push_back(newImage);

		ofLog() << "<import image: " << imagePath << ">";
	}
	catch (exception& e) {
		ofLog() << e.what();
	}
}
	