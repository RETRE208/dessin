#pragma once

#include "ofMain.h"

class Camera
{
public:
	Camera();

	void draw();
	void begin();
	void end();

	ofCamera* cam;
	float x;
	float y;
	float z;
};

