#pragma once
#include "Point.h"

//Ax + By + c == 0
struct Line
{
	double a, b, c;
	constexpr Line (const Point& P1, const Point& P2) : a (), b (), c ()
	{
		a = P1.y - P2.y;
		b = P1.x - P2.x;
		if ( a != 0 ) a = -1 / a;
		else b = -1 / b;
		c = -(a * P1.x) - (b * P1.y);
	}
};

