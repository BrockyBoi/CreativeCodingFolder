#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofxFloatSlider radius;
		ofxFloatSlider colorR;
		ofxFloatSlider colorG;
		ofxFloatSlider colorB;
		ofxPanel gui;
		ofxPanel gui1;
		ofxPanel gui2;
		ofxPanel gui3;

		ofxBox2dRect rect;
		ofxBox2d world;
		
};
