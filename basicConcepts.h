#pragma once
#define accuracy 10e-5

#include <cmath>

struct point
{
	double x;
	double y;
	double z;
	point(double x0, double y0, double z0)
	{
		x = x0; y = y0; z = z0;
	};
	point()
	{
		x = 0; y = 0; z = 0;
	};
};

//
unsigned long factorial(const unsigned int n, const unsigned int countFrom = 1);

//
unsigned int binomialCoefficient(unsigned int i, unsigned int n);

//
bool isNotOneLine(point a, point b, point c);

point tPoint(point a, point b, double t);