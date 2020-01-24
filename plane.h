#pragma once
#include "basicConcepts.h"

class plane
{
public:
	plane(point a, point b, point c);
	~plane();
	point getProjectionPoint(point m);
private:
	double A;
	double B;
	double C;
	double D;
};

