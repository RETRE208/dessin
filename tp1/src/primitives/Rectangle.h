#pragma once

#include "ofMain.h"
namespace tp1{

	class Rectangle
	{
	public:
		Rectangle();
		bool inside(ofPoint mouse);
		void draw();

		float x;
		float y;
		int width;
		int height;
		ofColor color;
	};
}



