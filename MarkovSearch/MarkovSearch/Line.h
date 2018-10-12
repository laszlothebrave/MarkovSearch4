#pragma once
#include "Point.h"
#include <cassert>

//Ax + By + c == 0
struct Line
{
	double a, b, c;

	constexpr Line (const Point& P1, const Point& P2) :
		a (P2.y - P1.y),
		b (P1.x - P2.x),
		c (-(a * P1.x) - (b * P1.y))
	{
		assert (a*P1.x + b * P1.y + c <= 10e-10);
		assert (a*P2.x + b * P2.y + c <= 10e-10);
	}

	constexpr double operator()(const double&x, const double& y)const
	{
		return a * x + b * y + c;
	}

	constexpr double operator()(const Point& p)const
	{
		return operator()(p.x, p.y);
	}
};

