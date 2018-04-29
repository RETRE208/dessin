#pragma once
#include "ofxPostProcessing.h"

class Filter
{
public:
	Filter();

	void setup();
	ofxPostProcessing* getBlurFilter();
	ofxPostProcessing* getAAFilter();
	ofxPostProcessing* getBloomFilter();
	ofxPostProcessing* getContrastFilter();

	ofxPostProcessing blur;
	ofxPostProcessing antiAliasing;
	ofxPostProcessing bloom;
	ofxPostProcessing contrast;
};

