// MarkovSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Polynomial.h"
#include "Point.h"
#include "Triangle.h"
#include "Xor128.h"


int main ()
{
	Triangle t (Point (-0.2, -0.1), Point (0.2, 1), Point (1.2, 0));
	Polynomial p (10, 11, 53, 2, 13);
	Polynomial b = p;
	
	std::cout << "Extrema: " << p.getExtremaOnTriangle (t) << '\n';
	std::cout << "Najmniejsza wysokosc trojkata:  " << t.getWidth () << std::endl;
	std::cout << p << '\n';
}
