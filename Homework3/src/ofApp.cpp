#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui1.setup();
	gui2.setup();
	gui3.setup();
	gui.add(radius.setup("Position", 300, 0, 1000));
	gui.add(colorR.setup("Red", 125, 0, 255));
	gui.add(colorG.setup("Green", 125, 0, 255));
	gui.add(colorB.setup("Blue", 125, 0, 255));

	world.init();
	world.setGravity(0, 3);
	rect.setup(world.getWorld(), 300, 250, 300, 400);
	
	rect.setPosition(radius, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	gui1.draw();
	gui2.draw();
	gui3.draw();
	rect.draw();
	ofFill();
	ofSetColor(colorR, colorG, colorB);
	//ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, radius);
	rect.setPosition(radius, 400);
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
