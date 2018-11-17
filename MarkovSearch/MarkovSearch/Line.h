#pragma once
#include "pch.h"
#include <cassert>

//Ax + By + c == 0
struct Line
{
	double a, b, c;

	constexpr Line (const Point& p1, const Point& p2) :
		a (p2.y - p1.y),
		b (p1.x - p2.x),
		c (-(a * p1.x) - (b * p1.y))
	{
		assert (a*p1.x + b * p1.y + c <= 10e-10);
		assert (a*p2.x + b * p2.y + c <= 10e-10);
	}

	constexpr double operator()(const double&x, const double& y) const
	{
		return a * x + b * y + c;
	}

	constexpr double operator()(const Point& p) const
	{
		return operator()(p.x, p.y);
	}
};