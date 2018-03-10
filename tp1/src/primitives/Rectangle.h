#pragma once

#include "ofMain.h"
namespace tp1{

	class Rectangle
	{
	public:
		Rectangle();
		void draw();

		bool isFill;
		float x;
		float y;
		int width;
		int height;
		float lineWidth;
		ofColor primaryColor;
		ofColor secondaryColor;

	};
}



