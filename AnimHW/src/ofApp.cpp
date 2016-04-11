#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255, 255, 255, 255);
	velX = -.05;
	velY = -.01;
	grav = .0005f;
	xPos = 0;
	yPos = -10;

	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	velY += grav;

	if (yPos > ofGetHeight())
		velY = -velY;
	if (xPos > ofGetWidth() || xPos < 0 || ofDist(xPos, yPos, mouseX, mouseY) < 10)
		velX = - velX;

	xPos += velX;
	yPos += velY;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(yPos / ofGetHeight() * 255, xPos / ofGetHeight() * 255, 100);
	ofFill();
	ofDrawCircle(xPos, yPos, 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP)
		grav += .0005;
	else if (key == OF_KEY_DOWN)
		grav -= .0005;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_1)
	{
		yPos -= 50;
	}
	if (button == OF_MOUSE_BUTTON_3)
		yPos += 50;
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
