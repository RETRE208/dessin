#include "MainPanel.h"


void MainPanel::setup() {
	gui.setup();
	gui.add(intSlider.setup("int slider", 0, 0, 300));
	gui.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
	gui.add(toggle.setup("toggle", false));
	button.addListener(this, &MainPanel::togglePrimitivePanel);
	gui.add(button.setup("button"));
}

void MainPanel::draw() {
	gui.draw();
}

void MainPanel::togglePrimitivePanel() {
	cout << "Called" << endl;
	draw();
}