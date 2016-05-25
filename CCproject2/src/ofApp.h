#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

//Listen on port 7000
#define PORT 7000

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

		ofVideoGrabber myVideoGrabber;
		unsigned char* videoData;
		ofTexture myTexture;

		float colorDistance;

		int camWidth, camHeight, maxPixel, threshold;

		float ex, ey, easing, normalizedX, normalizedY;

		ofPoint pointer;
		int xOfPixelWithClosestColor = ofGetWidth();
		int yOfPixelWithClosestColor = ofGetHeight();

		ofColor setColor;

		ofPolyline line;

		bool pointVisible;
		bool visibleLastFrame;

		int xOffset, yOffset;

		vector<ofPolyline> lineList;

		int lineCounter;

		ofxOscReceiver receiver;

		float colorR;
		float colorG;
		float colorB;
		float drawingSize;
};
