#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::blue);

	ofSetLineWidth(5);
	ofFill();
	ofSetColor(ofColor::darkRed);
	ofSetCircleResolution(50);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 250);

	ofNoFill();
	ofSetColor(ofColor::black);
	ofSetLineWidth(3);

	ofDrawLine(225, 60, 375, 540);
	ofDrawLine(375, 60, 225, 540);
	ofDrawLine(375 + 62.5, 85, 225 - 62.5, 515);
	ofDrawLine(300 - 137.5, 85, 300 + 137.5, 515);
	ofDrawLine(100, 145, 500, 455);
	ofDrawLine(500, 145, 100, 455);
	ofDrawLine(60, 210, 540, 390);
	ofDrawLine(600 - 60, 210, 600 - 540, 390);
	ofDrawLine(300, 50, 300, 550);
	ofDrawLine(50, 300, 550, 300);

	ofDrawCircle(300, 300, 25);
	ofDrawCircle(300, 300, 55);
	ofDrawCircle(300, 300, 95);
	ofDrawCircle(300, 300, 135);
	ofDrawCircle(300, 300, 175);
	ofDrawCircle(300, 300, 215);
	ofDrawCircle(300, 300, 255);
	ofFill();
	ofSetLineWidth(7);
	ofSetColor(ofColor::white);
	ofDrawTriangle(275, 300, 115, 350, 100, 175);
	ofDrawTriangle(325, 300, 485, 350, 500, 175);

	ofNoFill();
	ofSetColor(ofColor::black);
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 252);
	ofDrawTriangle(275, 300, 115, 350, 100, 175);
	ofDrawTriangle(325, 300, 485, 350, 500, 175);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
