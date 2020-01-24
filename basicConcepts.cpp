#include "basicConcepts.h"

unsigned long factorial(const unsigned int n, const unsigned int countFrom)
{
	unsigned long result = 1;
	for (unsigned int i = countFrom; i <= n; ++i)
		result *= i;
	return result;
}

unsigned int binomialCoefficient(unsigned int n, unsigned int i)
{
	unsigned int start = n - i;
	if (start < i)
	{
		start += i;
		i = start - i;
		start -= i;
	}
	return factorial(n, start + 1) / factorial(i);
}

bool isNotOneLine(point a, point b, point c)
{
	double ab = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.x - a.z), 2));
	double cb = sqrt(pow((b.x - c.x), 2) + pow((b.y - c.y), 2) + pow((b.x - c.z), 2));
	double ac = sqrt(pow((c.x - a.x), 2) + pow((c.y - a.y), 2) + pow((c.x - a.z), 2));
	return (abs(ab + cb - ac) > accuracy) && (abs(ab + ac - cb) > accuracy) && (abs(ac + cb - ab) > accuracy);
}

point tPoint(point a, point b, double t)
{
	point result;
	double lambda = (1 - t) / t;
	result.x = (a.x + lambda * b.x) / (1 + lambda);
	result.y = (a.y + lambda * b.y) / (1 + lambda);
	result.z = (a.z + lambda * b.z) / (1 + lambda);
	return result;
}