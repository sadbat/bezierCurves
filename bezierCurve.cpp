#include "bezierCurve.h"
#include <functional>

bezierCurve::bezierCurve(std::vector<point> basicPoints, unsigned int amountOfPoints)
{
	this->rank = basicPoints.size() - 1;
	referencePoints = basicPoints;
	if (amountOfPoints) //------!
		detalization = 1.0 / amountOfPoints;
}


bezierCurve::~bezierCurve()
{
	referencePoints.clear();
}

point bezierCurve::getDeCasteljauPoint(std::vector<point> points, double t)
{
	int numPoints = points.size() - 1;
	if (numPoints == 1)
		return tPoint(points.front(), points.back(), t);
	
	std::vector<point> computedPoints(numPoints);
	point startSegment = points.front();
	for (std::vector<point>::iterator it = ++points.begin(); it != points.end(); ++it)
	{
		computedPoints.push_back(tPoint(startSegment, *it, t));
		startSegment = *it;
	}
	return getDeCasteljauPoint(computedPoints, t);
}

point bezierCurve::computeDeCasteljauPoint(double t)
{
	return getDeCasteljauPoint(referencePoints, t);
}

point bezierCurve::computePointByEquation(double t)
{
	point current;
	unsigned int c;
	int i = 0;
	for(auto it : referencePoints)
	{
		c = binomialCoefficient(rank + 1, i);
		current.x += c * t * it.x;
		current.y += c * t * it.y;
		current.z += c * t * it.z;
		++i;
	}
	return current;
}
//!!!!!!!!! TODO: shared_ptr, OpenGL, try []->... functions
void bezierCurve::computePoints(algorithm computingType)
{
	/*std::function<point(double)> *computePoint;
	switch (computingType)
	{
	case byEquation:
		computePoint = computePointByEquation;
		break;
	default:
		computePoint = computeDeCasteljauPoint;
		break;
	}*/

	for (double t = 0; t < 1; t += this->detalization)
	{
		this->listOfPoints.push_back(computingType == algorithm::byEquation ? computePointByEquation (t) : computeDeCasteljauPoint (t));
	}
}

std::vector<point> bezierCurve::getProjection(plane planeForProjection)
{
	std::vector<point> projection;
	for (std::vector<point>::iterator i = this->listOfPoints.begin(); i != this->listOfPoints.end(); ++i)
	{
		projection.push_back(planeForProjection.getProjectionPoint(*i));
	}
	return projection;
}