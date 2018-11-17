#pragma once

#include "pch.h"

namespace utils
{
	//x1<=x2<=x3 || x3<=x2<=x1
	constexpr bool areOrdered (const double& x1, const double& x2, const double& x3)
	{
		return x3 <= x2 == x2 <= x1;
	}

	//p2 on [p1,p3]
	constexpr bool isOnInterval (const Point& p1, const Point& p2, const Point& p3)
	{
		return areOrdered (p1.x, p2.x, p3.x) && areOrdered (p1.y, p2.y, p3.y);
	}

	constexpr double pow2 (const double& val)
	{
		return val * val;
	}
}