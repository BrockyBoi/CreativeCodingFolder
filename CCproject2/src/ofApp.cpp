#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	camWidth = 320;
	camHeight = 240;

	myVideoGrabber.setDeviceID(1);
	myVideoGrabber.initGrabber(camWidth, camHeight);

	ofBackground(ofColor::black);
	ofSetBackgroundAuto(false);

	setColor = ofColor::blue;

	easing = 0.95;

	normalizedX = ofGetWidth() / camWidth;
	normalizedY = ofGetHeight() / camHeight;

	//ofSetVerticalSync(true);
	ofSetFrameRate(60);

	threshold = 100;

	pointVisible = false;

	receiver.setup(PORT);

	drawingSize = 25;
	ofSetColor(ofColor::blue);
}

//--------------------------------------------------------------
void ofApp::update(){
	myVideoGrabber.update();

	// Code fragment for tracking a spot with a certain target color. 
	float rTarget = 0;
	float gTarget = 255;
	float bTarget = 0;

	float maxBrightness = 150;

	// these are used in the search for the location of the pixel 
	if (myVideoGrabber.isFrameNew())
	{
		pointVisible = false;
		for (int y = 0; y < camHeight; y++)
		{
			for (int x = 0; x < camWidth; x++)
			{
				//Extract the color components of the pixel at (x,y)
				ofColor colorAtXY = myVideoGrabber.getPixels().getColor(x, y);
				float rAtXY = colorAtXY.r;
				float gAtXY = colorAtXY.g;
				float bAtXY = colorAtXY.b;

				// Compute the difference between those (r,g,b) values 
				// and the (r,g,b) values of our target color
				float rDif = rAtXY - rTarget; // difference in reds 
				float gDif = gAtXY - gTarget; // difference in greens 
				float bDif = bAtXY - bTarget; // difference in blues 

											  // The Pythagorean theorem gives us the Euclidean distance.
				colorDistance = sqrt(rDif*rDif + gDif*gDif + bDif*bDif);

				float brightness = colorAtXY.getBrightness();

				if (colorDistance < threshold && brightness > maxBrightness)
				{
					xOfPixelWithClosestColor = x * normalizedX + xOffset;
					yOfPixelWithClosestColor = y * normalizedY + yOffset;
					pointVisible = true;
					break;
				}

				//visibleLastFrame = pointVisible;
			}
			if (pointVisible)
				break;
		}
	}

	ofPoint prevPointer = pointer;
	pointer.x = pointer.x + (xOfPixelWithClosestColor - pointer.x) * easing;
	pointer.y = pointer.y + (yOfPixelWithClosestColor - pointer.y) * easing;

	//line.addVertex(pointer);
	//lineList.at(lineCounter).addVertex(pointer);

	//if (pointVisible && visibleLastFrame && pointer.distance(prevPointer) > 1.5) {
	//	//lineList.curveTo(pointer);
	//	lineList.at(lineCounter).curveTo(pointer);
	//}
	//else if (!visibleLastFrame && pointVisible)
	//{
	//	lineCounter++;
	//	ofPolyline l;
	//	lineList.push_back(l);
	//}

	while (receiver.hasWaitingMessages())
	{
		ofxOscMessage m;
		receiver.getNextMessage(m);

		if (m.getAddress() == "/master/red")
		{
			colorR = m.getArgAsFloat(0);// * 255;
		}
		if (m.getAddress() == "/master/blue")
		{
			colorB = m.getArgAsFloat(0);// * 255;
		}
		if (m.getAddress() == "/master/green")
		{
			colorG = m.getArgAsFloat(0);// * 255;
		}
		if (m.getAddress() == "/master/level")
		{
			drawingSize = m.getArgAsFloat(0) * 50;
		}

		setColor = ofFloatColor(colorR, colorG, colorB);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(ofColor::white);
    myVideoGrabber.draw(10, 10);

	ofSetColor(setColor);
	ofDrawCircle(pointer, drawingSize);
	ofDrawCircle(ofGetWidth() - 50, 50, 30);
	
	//line.draw();
	//lineList[lineCounter].draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '-')
	{
		threshold -= 10;
	}
	if (key == '+')
	{
		if (threshold + 10 < 230)
			threshold += 10;
	}

	if (key == ' ')
	{
		/*line.clear();
		for (int i = 0; i < lineList.size; i++)
		{
			lineList.clear();
		}*/

		ofSetColor(ofColor::black);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}

	if (key == '6')
	{
		xOffset += 10;
	}
	if (key == '4')
	{
		xOffset -= 10;
	}
	if (key == '8')
	{
		yOffset -= 10;
	}
	if (key == '2')
	{
		yOffset += 10;
	}
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
