#include "ImagePanel.h"

void ImagePanel::setup(string path)
{
	newImage.load(path);

	x = 200;
	y = 200;
	imageWidth = newImage.getWidth();
	imageHeight = newImage.getHeight();

	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	gui->addHeader("Image Panel");
	sliderX = gui->addSlider("Image X", 0, ofGetWidth(), 200);
	sliderY = gui->addSlider("Image Y", 0, ofGetHeight(), 200);
	sliderWidth = gui->addSlider("Image WIDTH", 0, ofGetWidth(), newImage.getWidth());
	sliderHeight = gui->addSlider("Image HEIGHT", 0, ofGetHeight(), newImage.getHeight());

	sliderX->bind(x);
	sliderY->bind(y);
	sliderWidth->bind(imageWidth);
	sliderHeight->bind(imageHeight);
}

void ImagePanel::update()
{
	if (ofGetMousePressed() && gui->getMouseDown() == false) {
		ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
		if (mouse.distance(ofPoint(x, y)) <= imageHeight) {
			x = mouse.x;
			y = mouse.y;
		}
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
