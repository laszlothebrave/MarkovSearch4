#include "pch.h"
#include "Triangle.h"
#include "Point.h"
#include <math.h>

Triangle::Triangle(const Point& P1, const Point& P2, const Point& P3) : P1(P1), P2(P2), P3(P3), L1(Line(P1, P2)), L2(Line(P2, P3)), L3(Line(P3, P1)), width(DBL_MAX) {
	setWidth( fabs(L1.a*P3.x + L1.b*P3.y + L1.c)/sqrt(L1.a*L1.a+L1.b*L1.b) );
	setWidth(fabs(L2.a*P1.x + L2.b*P1.y + L2.c) / sqrt(L2.a*L2.a + L2.b*L2.b));
	setWidth(fabs(L3.a*P2.x + L3.b*P2.y + L3.c) / sqrt(L3.a*L3.a + L3.b*L3.b));
}

const Point& Triangle::getPoint1() const
{
	return P1;
}

const Point& Triangle::getPoint2() const
{
	return P2;
}

const Point& Triangle::getPoint3() const
{
	return P3;
}

const Line& Triangle::getLine1() const
{
	return L1;
}

const Line& Triangle::getLine2() const
{
	return L2;
}

const Line& Triangle::getLine3() const
{
	return L3;
}

void Triangle::setWidth(const double& candidate)
{
	if (candidate < width) width = candidate;
}

double Triangle::getWidth() const
{
	return width;
}
