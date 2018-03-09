#include "SelectorPanel.h"

void SelectorPanel::setup() {
	selectorPanel.setup();
	selectorPanel.setPosition(0, 310);
}

void SelectorPanel::draw() {
	selectorPanel.draw();
}

void SelectorPanel::addToggle(string name) {
	toggle = new ofxToggle();
	toggle->setup(false);
	toggle->setName(name);
	selectorPanel.add(toggle);
	toggleList.push_back(toggle);
}

void SelectorPanel::removeToggle(string name) {
	cout << name << endl;
	for (int i = 0; i < toggleList.size(); i++) {
		if (toggleList[i]->getName() == name) {
			cout << toggleList[i]->getName() << endl;
			toggleList.erase(toggleList.begin() + i);
		}
	}

	selectorPanel.clear();
	for (int i = 0; i < toggleList.size(); i++) {
		selectorPanel.add(toggleList[i]);
	}
}

bool SelectorPanel::getIfSelected(string name) {
	for (int i = 0; i < toggleList.size(); i++) {
		if ((toggleList[i]->getName() == name) && selectorPanel.getToggle(name)) {
			return true;
		}
	}
	return false;
}