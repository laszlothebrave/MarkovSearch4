#pragma once
#include "Point.h"
#include "Line.h"

class Triangle
{
private:
	Point P1, P2, P3;
	Line L1, L2, L3;
	double width = 0;
public:
	Triangle(const Point& P1, const Point& P2, const Point& P3);
	const Point& getPoint1() const;
	const Point& getPoint2() const;
	const Point& getPoint3() const;
	const Line& getLine1() const;
	const Line& getLine2() const;
	const Line& getLine3() const;
	void setWidth(const double& candidate);
	double getWidth() const;
};

