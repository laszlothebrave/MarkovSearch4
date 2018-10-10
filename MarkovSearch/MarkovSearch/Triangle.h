#pragma once
#include <tuple>

#include "Point.h"
#include "Line.h"

class Triangle
{
private:
	const Point P1, P2, P3;
	const Line L1, L2, L3;
	double width;

	constexpr void updateWidth (const double& candidate);

public:
	Triangle (const Point& P1, const Point& P2, const Point& P3);

	constexpr auto getPoints ()const
	{
		return std::tuple<Point, Point, Point>{ P1, P2, P3 };
	}

	constexpr auto getLines ()const
	{
		return std::tuple<Line, Line, Line>{ L1, L2, L3 };
	}

	constexpr double getWidth ()const
	{
		return width;
	}
};

