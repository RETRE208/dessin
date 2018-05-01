#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "ofxGui.h"
#include <tuple>
#include "../views/SpherePanel.h"

using namespace std;

class RayTracingRenderWindow : public ofBaseApp {
public:
	ofFbo fbo;
	int w, h;
	ofShader trace;

	vector<SpherePanel*> spheres;

	RayTracingRenderWindow(vector<SpherePanel*> spheres) {
		this->spheres = spheres;
	}

	void setup() {
		ofSetFrameRate(150);
		trace.load("ray");
		w = ofGetScreenWidth();
		h = ofGetScreenHeight();
		fbo.allocate(w, h);
		fbo.begin();
		ofClear(0, 0, 0, 0);
		fbo.end();
	}

	void update() {
		ofSetWindowTitle(ofToString(ofGetFrameRate()));
	}

	void draw() {
		ofBackgroundGradient(255, 0);
		trace.begin();
		trace.setUniform1f("u_aspect_ratio", w / h);
		for (int i = 0; i < spheres.size(); i++) {
			Sphere* sphere = spheres[i]->sphere;
			float convertedRadius = float(sphere->mRadius) / 636;
			tuple<float, float, float> convertedCoordinates = this->converter(sphere->x, sphere->y, sphere->z);
			trace.setUniform1f("sphere_radius_" + to_string(i), convertedRadius);
			trace.setUniform3f("sphere_position_" + to_string(i), get<0>(convertedCoordinates), get<1>(convertedCoordinates), get<2>(convertedCoordinates));
			trace.setUniform3f("sphere_color_" + to_string(i), sphere->color.r, sphere->color.g, sphere->color.b);
		}
		trace.setUniform3f("plane_position", 0., -.5, 0.);
		trace.setUniform3f("plane_normal", 0., 1., 0.043);
		trace.setUniform1f("light_intensity", 0.4);
		trace.setUniform2f("light_specular", 0, 50);
		trace.setUniform3f("light_position", 5., 5., -5.);
		trace.setUniform3f("light_color", 0, 0, 0);
		trace.setUniform1f("ambient", 0.2);
		trace.setUniform3f("O", 0., 0., -1.);
		fbo.draw(-100, -100);
		trace.end();
		gui.draw();
	}

	tuple<float, float, float> converter(int x, int y, int z) {
		float convertedX, convertedY, convertedZ;
		convertedX = (x * 5) / 1366;
		convertedY = (y * 5) / 700;
		convertedZ = (y * 5) / 360;
		return make_tuple(convertedX, convertedY, convertedZ);
	}
};