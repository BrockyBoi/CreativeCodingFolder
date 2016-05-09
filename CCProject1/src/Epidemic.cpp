#include "Epidemic.h"

Epidemic::Epidemic()
{
}

Epidemic::Epidemic(std::string n, float firstYear, float lastYear, float totalKilled, float population)
{
	name = n;
	y1 = firstYear;
	y2 = lastYear;
	tK = totalKilled;
	pop = population;
}

void Epidemic::setup(std::string n, float firstYear, float lastYear, float totalKilled, float population)
{
	name = n;
	y1 = firstYear;
	y2 = lastYear;
	tK = totalKilled;
	pop = population;
}

float Epidemic::getPopulation()
{
	return pop;	
}

float Epidemic::getYearOne()
{
	return y1;
}

float Epidemic::getYearTwo()
{
	return y2;
}

float Epidemic::yearSpan()
{
	return y2 - y1;
}

float Epidemic::getTotalKilled()
{
	return tK;
}


float Epidemic::percentageKilled()
{
	return (float)(tK / pop);
}


Epidemic::~Epidemic()
{
}
