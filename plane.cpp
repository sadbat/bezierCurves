#include "plane.h"

plane::plane(point a, point b, point c)
{
	A = a.y * (b.z - c.z) + b.y * (c.z - a.z) + c.y * (a.z - b.z);
	B = a.z * (b.x - c.x) + b.z * (c.x - a.x) + c.z * (a.x - b.x);
	C = a.x * (b.y - c.y) + b.x * (c.y - b.y) + c.x * (a.y - b.y);
	D = - a.x * (b.y * c.z - c.y * b.z) + b.x * (c.y * a.z - a.y * c.z) + c.x * (a.y * b.z - b.y * a.z);
}

point plane::getProjectionPoint(point m)
{
	point result;
	double lambda = -(A * m.x + B * m.y + C * m.z + D) / (A * A + B * B + C * C);
	result.x = m.x + A * lambda;
	result.y = m.y + B * lambda;
	result.z = m.z + D * lambda;
	return result;
}

plane::~plane()
{
}
