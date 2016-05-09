#pragma once

#include "Strings.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "Epidemic.h"
#include "ofxCsv.h"
#include "ofxButton.h"

using namespace wng;

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
		void setRadius();
		void setCurrentKilled();
		void setDeathCircle();
		void setPopCircle();

		int counter;
		float screenMultiplier;

		float year;
		ofxFloatSlider years;
		ofxPanel gui;

		float deathRadius;
		float popRadius;
		float startingRadius;
		float currentKilled;

		std::vector<Epidemic> epidemicList;

		Epidemic plague;
		Epidemic spanishFlu;
		Epidemic HIV;
		Epidemic justinian;
		Epidemic cocoliztli;

		int variableCounter;
		bool overlapping;

		ofxCsv csv;

		bool automatic;
		bool usingArrows;
		bool displayAll;

		std::string month;
		ofTrueTypeFont yearsText;
		ofTrueTypeFont epidemicTitle;
		ofTrueTypeFont popTitle;
		ofTrueTypeFont popCountText;
		ofTrueTypeFont deathTitle;
		ofTrueTypeFont deathCountText;
};

