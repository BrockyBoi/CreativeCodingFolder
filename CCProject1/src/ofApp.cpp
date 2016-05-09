#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Load a CSV File.
	csv.loadFile(ofToDataPath("diseases.txt"));

	cout << "Print out a specific CSV value" << endl;
	cout << csv.getString(1,0) << endl;

	for (int i = 0; i < csv.data.size(); i++)
	{
		Epidemic e(csv.getString(i, 0), csv.getFloat(i, 1), csv.getFloat(i, 2), csv.getFloat(i, 3), csv.getFloat(i, 4));
		epidemicList.push_back(e);
	}

	gui.setup();
	gui.add(years.setup("Year: ", epidemicList.at(counter).getYearOne(), epidemicList.at(counter).getYearOne(), epidemicList.at(counter).getYearTwo()));
	

	setRadius();
	startingRadius = popRadius;

	ofSetBackgroundColor(ofColor::black);
	ofSetCircleResolution(150);

	ofSetColor(ofColor::white);
	epidemicTitle.loadFont(OF_TTF_SANS, 35);
	popCountText.loadFont(OF_TTF_SANS, 25);
	deathCountText.loadFont(OF_TTF_SANS, 25);
	ofSetColor(ofColor::white);
	popTitle.loadFont(OF_TTF_SANS, 32);
	deathTitle.loadFont(OF_TTF_SANS, 32);
	yearsText.loadFont(OF_TTF_SANS, 32);
}

//--------------------------------------------------------------
void ofApp::update(){

	setCurrentKilled();
	setRadius();

	//ex += (ofGetMouseX() - ex) * easing;
	if(!automatic && !usingArrows)
		years = ofMap(ofGetMouseX(), 0, ofGetWidth(), epidemicList.at(counter).getYearOne(), epidemicList.at(counter).getYearTwo());
	
	if (automatic)
	{
		if (counter < csv.data.size() - 1)
		{
			years = years + .0075;
			if (years > epidemicList.at(counter).getYearTwo())
			{
				Sleep(2000);
				counter++;
				years = epidemicList.at(counter).getYearOne();
				years.setMin(epidemicList.at(counter).getYearOne());
				years.setMax(epidemicList.at(counter).getYearTwo());
			}
		}
		else if(counter == csv.data.size() - 1)
		{
			years = years + .0075;
			if (years > epidemicList.at(counter).getYearTwo())
			{
				Sleep(2000);
				counter = 0;
				years = epidemicList.at(counter).getYearOne();
				years.setMin(epidemicList.at(counter).getYearOne());
				years.setMax(epidemicList.at(counter).getYearTwo());
			}
		}
	}

	float num = years;

	if (years - (int)years < .083)
	{
		month = "Jan";
	}
	else if (years - (int)years < .083 * 2)
	{
		month = "Feb";
	}
	else if (years - (int)years < .083 * 3)
	{
		month = "Mar";
	}
	else if (years - (int)years < .083 * 4)
	{
		month = "Apr";
	}
	else if (years - (int)years < .083 * 5)
	{
		month = "May";
	}
	else if (years - (int)years < .083 * 6)
	{
		month = "Jun";
	}
	else if (years - (int)years < .083 * 7)
	{
		month = "Jul";
	}
	else if (years - (int)years < .083 * 8)
	{
		month = "Aug";
	}
	else if (years - (int)years < .083 * 9)
	{
		month = "Sep";
	}
	else if (years - (int)years < .083 * 10)
	{
		month = "Oct";
	}
	else if (years - (int)years < .083 * 11)
	{
		month = "Nov";
	}
	else if (years - (int)years < .083 * 12)
	{
		month = "Dec";
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (!displayAll)
	{
		ofSetBackgroundAuto(true);
		setPopCircle();
		setDeathCircle();
		//gui.draw();
		//epidemicTitle.drawString("Years" + years, 10, 75);
		
	}
	else
	{
		for (int i = 0; i < csv.data.size(); i++)
		{
			ofFill();
			ofSetColor(ofColor::lightBlue, 150);
			float newRadius = (epidemicList.at(i).getPopulation()  * (450 / (float)epidemicList.at(i).getPopulation()) * (float)(epidemicList.at(i).getPopulation() / (float)1750));
			ofDrawCircle(500, ofGetHeight() / 2 - 20, newRadius);
			ofNoFill();
			ofSetLineWidth(5);
			ofSetColor(ofColor::black, 255);
			ofDrawCircle(500, ofGetHeight() / 2 - 20, newRadius);



			ofFill();
			ofSetLineWidth(1);
			ofSetColor(ofColor::darkRed, 150);
			float newDeathRadius = (epidemicList.at(i).getTotalKilled()  * (450 / (float)epidemicList.at(i).getPopulation()) * (float)(epidemicList.at(i).getPopulation() / (float)1750));
			ofDrawCircle(1300, ofGetHeight() / 2 - 20, newDeathRadius);


			ofSetColor(ofColor::white);
			popTitle.drawString("Totals", ofGetWidth() / 2, 75);
		}
	}

}

void ofApp::setCurrentKilled()
{
	currentKilled = (float)((years - epidemicList.at(counter).getYearOne()) / epidemicList.at(counter).yearSpan()) * epidemicList.at(counter).getTotalKilled();
}

void ofApp::setRadius()
{
	screenMultiplier = (450 / (float)epidemicList.at(counter).getPopulation());

	deathRadius = currentKilled * screenMultiplier;// * (float)(epidemicList.at(counter).getPopulation() / 6900);
	popRadius = (epidemicList.at(counter).getPopulation() - currentKilled) * screenMultiplier;// * (float)(epidemicList.at(counter).getPopulation() / (float)7000);

}

void ofApp::setPopCircle()
{
	ofFill();
	ofSetColor(ofColor::lightBlue, 255);
	if (overlapping)
	{
		ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 - 20, popRadius);
		ofSetColor(ofColor::black, 255);
		popCountText.drawString(ofToString((epidemicList.at(counter).getPopulation() - currentKilled), 2) + " million", ofGetWidth() / 2 - 100, 150);
		ofSetColor(ofColor::white);
		popTitle.drawString("Population Count", ofGetWidth() / 2 - 175, 40);
		ofSetColor(ofColor::gray);
		epidemicTitle.drawString(csv.getString(counter, 0), 10, 40);
		int num = years;
		yearsText.drawString(month + " " + ofToString(num) , 10, 90);
	}
	else
	{
		ofDrawCircle(500, ofGetHeight() / 2 - 20, popRadius);
		ofSetColor(ofColor::black, 255);
		popCountText.drawString(ofToString((epidemicList.at(counter).getPopulation() - currentKilled), 2) + " million", 400, ofGetHeight() / 2 - 25);
		ofSetColor(ofColor::white);
		popTitle.drawString("Population Count", 325, 40);
		ofSetColor(ofColor::gray);
		epidemicTitle.drawString(csv.getString(counter, 0), ofGetWidth() /2 - 275, 40);
		int num = years;
		yearsText.drawString(month + " " + ofToString(num), ofGetWidth() / 2 - 275, 90);
	}

	ofNoFill();
	ofSetLineWidth(5);
	ofSetColor(ofColor::black, 255);
	if (overlapping)
		ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 - 20, startingRadius);
	else
		ofDrawCircle(500, ofGetHeight() / 2 - 20, startingRadius);
}

void ofApp::setDeathCircle()
{
	ofFill();
	ofSetLineWidth(1);
	ofSetColor(ofColor::darkRed, 150);

	if (overlapping)
	{
		ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2 - 20, deathRadius);
		ofSetColor(ofColor::black, 255);
		deathCountText.drawString(ofToString(currentKilled, 2) + " million", ofGetWidth() / 2 - 75, ofGetHeight() / 2);
		ofSetColor(ofColor::white);
		deathTitle.drawString("Death Toll", ofGetWidth() / 2 - 100, ofGetHeight() / 2 - 200);
	}
	else
	{
		ofDrawCircle(1400, ofGetHeight() / 2 - 20, deathRadius);
		ofSetColor(ofColor::black, 255);
		deathCountText.drawString(ofToString(currentKilled, 2) + " million", 1325, ofGetHeight() / 2 - 25);
		ofSetColor(ofColor::white);
		deathTitle.drawString("Death Toll", 1300, 40);
	} 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RIGHT)
	{
		if (counter < csv.data.size() - 1)
		{
			counter++;
			years = epidemicList.at(counter).getYearOne();
			years.setMin(epidemicList.at(counter).getYearOne());
			years.setMax(epidemicList.at(counter).getYearTwo());
			//setRadius();
			//startingRadius = popRadius;
		}
	}
	else if(key == OF_KEY_LEFT)
	{
		if (counter > 0)
		{
			counter--;
			years = epidemicList.at(counter).getYearOne();
			years.setMin(epidemicList.at(counter).getYearOne());
			years.setMax(epidemicList.at(counter).getYearTwo());
			//setRadius();
			//startingRadius = popRadius;
		}
	}

	if (key == OF_KEY_UP)
	{
		if (years < epidemicList.at(counter).getYearTwo())
			years = (float)(years + .083);

		automatic = false;
		usingArrows = true;
	}

	if (key == OF_KEY_DOWN)
	{
		if (years > epidemicList.at(counter).getYearOne())
			years = (float)(years - .083);

		automatic = false;
		usingArrows = true;
	}

	if (key == OF_KEY_RETURN)
	{
		if (displayAll)
			displayAll = false;
		else displayAll = true;
	}

	if (key == ' ')
	{
		if (overlapping)
			overlapping = false;
		else overlapping = true;
	}

	if (key == OF_KEY_BACKSPACE)
	{
		if (usingArrows)
			usingArrows = false;
		else usingArrows = true;
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
	if (automatic)
	{
		automatic = false;
	}
	else automatic = true;
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
