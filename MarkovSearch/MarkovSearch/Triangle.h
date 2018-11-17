#pragma once
#include "pch.h"

#include <tuple>
#include <algorithm>

struct Triangle
{
private:
	constexpr double calculateWidthSquare () const
	{
		const double h1 = utils::pow2 (l1.a*p3.x + l1.b*p3.y + l1.c) / (l1.a*l1.a + l1.b*l1.b);
		const double h2 = utils::pow2 (l2.a*p1.x + l2.b*p1.y + l2.c) / (l2.a*l2.a + l2.b*l2.b);
		const double h3 = utils::pow2 (l3.a*p2.x + l3.b*p2.y + l3.c) / (l3.a*l3.a + l3.b*l3.b);

		return std::min ({ h1, h2, h3 });
	}

public:
	const Point p1, p2, p3;
	const Line l1, l2, l3;
	const double width;

	constexpr Triangle (const Point& p1, const Point& p2, const Point& p3) :
		p1 (p1), p2 (p2), p3 (p3),
		l1 (Line (p1, p2)), l2 (Line (p2, p3)), l3 (Line (p3, p1)),
		width (calculateWidthSquare ())
	{
	}

	constexpr bool contains (const double x, const double y) const
	{
		return (l1 (x, y) <= 0) &&
			(l2 (x, y) <= 0) &&
			(l3 (x, y) <= 0);
	}

	constexpr inline bool contains (const Point p) const
	{
		return contains (p.x, p.y);
	}

	constexpr double getWidthSquare () const
	{
		return width;
	}

	double getWidth () const
	{
		return std::sqrt (width);
	}
};

