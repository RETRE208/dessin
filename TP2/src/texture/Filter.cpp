#include "Filter.h"


Filter::Filter(){}

void Filter::setup() {
	blur.init(ofGetWidth(), ofGetHeight());
	blur.createPass<ConvolutionPass>();
	antiAliasing.init(ofGetWidth(), ofGetHeight());
	antiAliasing.createPass<FxaaPass>();
	bloom.init(ofGetWidth(), ofGetHeight());
	bloom.createPass<BloomPass>();
	contrast.init(ofGetWidth(), ofGetHeight());
	contrast.createPass<ContrastPass>();
	noise.init(ofGetWidth(), ofGetHeight());
	noise.createPass<NoiseWarpPass>();
}

ofxPostProcessing* Filter::getBlurFilter() {
	return &blur;
}

ofxPostProcessing* Filter::getAAFilter() {
	return &antiAliasing;
}

ofxPostProcessing* Filter::getBloomFilter() {
	return &bloom;
}

ofxPostProcessing* Filter::getContrastFilter() {
	return &contrast;
}

ofxPostProcessing* Filter::getNoiseFilter() {
	return &noise;
}
