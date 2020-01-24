#pragma once
#include "curve.h"

enum algorithm {
	byEquation,
	deCasteljau
};

class bezierCurve:
	public curve
{
public:
	bezierCurve(std::vector<point> basicPoints, unsigned int amountOfPoints);
	~bezierCurve();
	std::vector<point> getProjection(plane planeForProjection);
	void computePoints(algorithm computingType = deCasteljau);
private:
	std::vector<point> referencePoints;
	point computePointByEquation(double t);
	point computeDeCasteljauPoint(double t);
	point getDeCasteljauPoint(std::vector<point> points, double t);
};

