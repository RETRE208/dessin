#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mainController.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	mainController.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key)
	{
	case 49:  // key 1
		texture.kernel_type = ConvolutionKernel::identity;
		texture.kernel_name = "identité";

		break;

	case 50:  // key 2
		texture.kernel_type = ConvolutionKernel::emboss;
		texture.kernel_name = "bosseler";
		
		break;

	case 51:  // key 3
		texture.kernel_type = ConvolutionKernel::sharpen;
		texture.kernel_name = "aiguiser";
		break;

	case 52:  // key 4
		texture.kernel_type = ConvolutionKernel::edge_detect;
		texture.kernel_name = "détection de bordure";
		break;

	case 53:  // key 5
		texture.kernel_type = ConvolutionKernel::blur;
		texture.kernel_name = "flou";
		break;

	default:
		break;
	}
	texture.filter();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
