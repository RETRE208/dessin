#include "ImagePanel.h"
#include "../controllers/MainController.h"

void ImagePanel::setup(string path, MainController* mainController)
{
	mainControllerInstance = mainController;
	newImage.load(path);
	newImage.setImageType(OF_IMAGE_COLOR_ALPHA);

	x = 200;
	y = 200;
	imageWidth = newImage.getWidth();
	imageHeight = newImage.getHeight();
	alpha = 255;

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->setWidth(200);
	gui->addHeader("Image Panel");
	sliderX = gui->addSlider("Image X", 0, ofGetWidth(), 200);
	sliderY = gui->addSlider("Image Y", 0, ofGetHeight(), 200);
	sliderWidth = gui->addSlider("Image WIDTH", 0, ofGetWidth(), newImage.getWidth());
	sliderHeight = gui->addSlider("Image HEIGHT", 0, ofGetHeight(), newImage.getHeight());
	embossBtn = gui->addButton("Emboss");
	sharpenBtn = gui->addButton("Sharpen");
	edgeDetectBtn = gui->addButton("Edge Detect");
	blurBtn = gui->addButton("Blur");
	sliderAlpha = gui->addSlider("Alpha", 0, 255, 255);
	alphaBtn = gui->addButton("Apply opacity");
	inverseBtn = gui->addButton("Inverse color");
	gridBtn = gui->addButton("Apply grid texture");

	sliderX->bind(x);
	sliderY->bind(y);
	sliderWidth->bind(imageWidth);
	sliderHeight->bind(imageHeight);
	sliderAlpha->bind(alpha);

	gui->onButtonEvent(this, &ImagePanel::onButtonEvent);
}

void ImagePanel::onButtonEvent(ofxDatGuiButtonEvent e) {
	if (e.target == embossBtn) {
		ofLog() << "Button emboss pressed";
		mainControllerInstance->applyTexture(2, &newImage);
	}
	else if (e.target == sharpenBtn) {
		ofLog() << "Button sharpen pressed";
		mainControllerInstance->applyTexture(3, &newImage);
	}
	else if (e.target == edgeDetectBtn) {
		ofLog() << "Button edge detect pressed";
		mainControllerInstance->applyTexture(4, &newImage);
	}
	else if (e.target == blurBtn) {
		ofLog() << "Button blur pressed";
		mainControllerInstance->applyTexture(5, &newImage);
	}
	else if (e.target == alphaBtn) {
		ofLog() << "Button alpha pressed";
		mainControllerInstance->changeImageOpacity(&newImage, alpha);
	}
	else if (e.target == inverseBtn) {
		ofLog() << "Button inversion pressed";
		mainControllerInstance->inversionImageColor(&newImage);
	}
	else if (e.target == gridBtn) {
		ofLog() << "Button grid pressed";
		mainControllerInstance->proceduralGridTexture(&newImage);
	}
}

void ImagePanel::draw()
{
	newImage.draw(
		x,
		y,
		imageWidth,
		imageHeight);
}
