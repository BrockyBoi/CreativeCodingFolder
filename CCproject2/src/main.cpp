#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context

	//ofAppGLFWWindow *window = (ofAppGLFWWindow*) ofGetWindowPtr();
	//ofGLFWWindowSettings settings = window->getSettings();
	//settings.monitor = 1;
	//window->setup(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
