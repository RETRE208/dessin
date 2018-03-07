#include "PrimitivePanel.h"


void PrimitivePanel::setup() {
	circleGroup.setup();
	parameterGroup.add(circleGroup.circleParameters);

	gui.setup(parameterGroup);
	gui.setPosition(215, 10);
}

void PrimitivePanel::draw() {
	circleGroup.draw();
	gui.draw();
}