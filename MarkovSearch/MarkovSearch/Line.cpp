#include "pch.h"
#include "Line.h"

Line::Line(const Point & P1, const Point & P2)
{
	b = P1.x - P2.x;
	a = P1.y - P2.y;
	if (a != 0) a = -1 / a;
	else b = -1 / b;
	c = - (a * P1.x) - (b * P1.y);
}
