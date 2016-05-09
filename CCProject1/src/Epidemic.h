#include "string"

#pragma once
class Epidemic
{
public:
	Epidemic();
	Epidemic(std::string n, float firstYear, float lastYear, float totalKilled, float population);
	~Epidemic();

	void setup(std::string n, float firstYear, float lastYear, float totalKilled, float population);
	float yearSpan();
	float getYearOne();
	float getYearTwo();
	float getPopulation();
	float getTotalKilled();
	float percentageKilled();
private:
	std::string name;
	float y1, y2;
	float tK, pop;

};

