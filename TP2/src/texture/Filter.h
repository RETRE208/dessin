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
		ofxPostProcessing* getNoiseFilter();

		ofxPostProcessing blur;
		ofxPostProcessing antiAliasing;
		ofxPostProcessing bloom;
		ofxPostProcessing contrast;
		ofxPostProcessing noise;
};

