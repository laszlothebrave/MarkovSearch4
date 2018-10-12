#pragma once

#include "pch.h"

struct Point
{
	double x, y;
	constexpr Point (const double& x, const double& y) : x (x), y (y) {};

	friend std::ostream& operator<<(std::ostream& out, const Point& val)
	{
		return out << "x: " << val.x << ", y: " << val.y;
	}
};
