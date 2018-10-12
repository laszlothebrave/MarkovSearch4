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

	constexpr void updateWidth (const double& candidate)
	{
		if (candidate < width) width = candidate;
	}

	constexpr double pow2 (const double& val) const
	{
		return val * val;
	}

public:
	constexpr Triangle (const Point& P1, const Point& P2, const Point& P3) : P1 (P1), P2 (P2), P3 (P3), L1 (Line (P1, P2)), L2 (Line (P2, P3)), L3 (Line (P1, P3)), width (DBL_MAX) {
		updateWidth (pow2 (L1.a*P3.x + L1.b*P3.y + L1.c) / (L1.a*L1.a + L1.b*L1.b));
		updateWidth (pow2 (L2.a*P1.x + L2.b*P1.y + L2.c) / (L2.a*L2.a + L2.b*L2.b));
		updateWidth (pow2 (L3.a*P2.x + L3.b*P2.y + L3.c) / (L3.a*L3.a + L3.b*L3.b));
	}

	constexpr auto getPoints ()const
	{
		return std::tuple{ P1, P2, P3 };
	}

	constexpr auto getLines ()const
	{
		return std::tuple{ L1, L2, L3 };
	}

	constexpr bool contains (const double& x, const double& y)const
	{
		return (L1 (x, y) <= 0) == (L1 (P3) <= 0) &&
			(L2 (x, y) <= 0) == (L2 (P1) <= 0) &&
			(L3 (x, y) <= 0) == (L3 (P2) <= 0);
	}

	constexpr inline bool contains (const Point& p)const
	{
		return contains (p.x, p.y);
	}

	constexpr double getWidthCube ()const
	{
		return width;
	}

	double getWidth ()const
	{
		return std::sqrt (width);
	}
};

