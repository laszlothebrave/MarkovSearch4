// MarkovSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Polynomial.h"
#include "Point.h"
#include "Triangle.h"

int main ()
{
	Triangle t = Triangle (Point (0, 0), Point (0, 0.5), Point (1, 0));
	std::cout << "Najmniejsza wysokosc trojkata:  " << t.getWidth () << std::endl;
}
