#pragma once
#include "basicConcepts.h"
#include "plane.h"
#include <vector>


class curve
{
public:
	curve();
	~curve();
	unsigned int getRank() { return rank; };
	virtual void computePoints() = 0;
	virtual std::vector<point> getProjection(plane planeForProjection) = 0;

protected:
	unsigned int rank;
	double detalization;
	std::vector<point> listOfPoints;
};

