#pragma once

#include "ofMain.h"
namespace tp1 {
	class Ellipse
	{
	public:
		Ellipse();
		void draw();

		bool isFill;
		float x;
		float y;
		float width;
		float height;
		float lineWidth;
		ofColor primaryColor;
		ofColor secondaryColor;
	};
}


