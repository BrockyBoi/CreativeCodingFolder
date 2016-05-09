#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camWidth = 640;
	camHeight = 480;

	//Open a video grabber for the default camera
	myVideoGrabber.initGrabber(camWidth, camHeight);

	//Create resources to store and display another copy of the data
	invertedVideoData = new unsigned char[camWidth * camHeight * 3];
	musicVideoData = new unsigned char[camWidth * camHeight * 3];
	randomVideoData = new unsigned char[camWidth * camHeight * 3];
	myTexture.allocate(camWidth, camHeight, GL_RGB);
	invertedTexture.allocate(camWidth, camHeight, GL_RGB);
	randomTexture.allocate(camWidth, camHeight, GL_RGB);

	maxPixel = 255;
}

//--------------------------------------------------------------
void ofApp::update(){
	//Ask the grabber to refresh the data
	myVideoGrabber.update();

	//if the grabber has fresh data
	if (myVideoGrabber.isFrameNew())
	{
		//Get pointer to the grabber's image data
		unsigned char* pixelData = myVideoGrabber.getPixels();

		int nTotalBytes = camHeight * camWidth * 3;

		for (int i = 0; i < nTotalBytes; i++)
		{
			invertedVideoData[i] = 255 - pixelData[i];

			if (pixelData[i] < 122)
				musicVideoData[i] = pixelData[i] * 2;

			if(pixelData[i] > 150)
				randomVideoData[i] = pixelData[i] / 2;
		}

		//for (int x = 0; x < camWidth; x++)
		//{
		//	for (int y = 0; y < camHeight; y++)
		//	{

		//	}
		//}

	//	ofDrawEllipse(maxPixel, maxPixel, 10, 10);
		//ofDrawEllipse()

		//Now stash the invereted data in an ofTexture
		invertedTexture.loadData(invertedVideoData, camWidth, camHeight, GL_RGB);
		myTexture.loadData(musicVideoData, camWidth, camHeight, GL_RGB);
		randomTexture.loadData(randomVideoData, camWidth, camHeight, GL_RGB);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(100, 100, 100);
	ofSetColor(255, 255, 255);

	//ofDrawEllipse(maxPixel / camWidth, maxPixel / camHeight, 10, 10);

	//Draw the grabber and the "negative" to it
	myVideoGrabber.draw(10, 10);
	invertedTexture.draw(660, 10);
	myTexture.draw(10, 500);
	randomTexture.draw(660, 500);
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
