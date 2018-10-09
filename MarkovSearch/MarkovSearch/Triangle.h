#pragma once
#include "Point.h"
#include "Line.h"

class Triangle
{
private:
	Point P1, P2, P3;
	Line L1, L2, L3;

public:
	Triangle(const Point& P1, const Point& P2, const Point& P3) : P1(P1), P2(P2), P3(P3), L1(Line(P1, P2)), L2(Line(P2, P3)), L3(Line(P3, P1)) {};
	const Point& getPoint1();
	const Point& getPoint2();
	const Point& getPoint3();
	const Line& getLine1();
	const Line& getLine2();
	const Line& getLine3();
};

