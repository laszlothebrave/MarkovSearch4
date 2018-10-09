// MarkovSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Polynomial.h"
#include "Point.h"
#include "Triangle.h"
#include "PolynomialAndDerivativePack.h"

int main()
{
	PolynomialAndDerivativePack p = PolynomialAndDerivativePack(Polynomial(1, 2, 3, 4, 5));
	Triangle t = Triangle(Point(0, 0), Point(0, 0.5), Point(1, 0));
	std::cout << "Najmniejsza wysokosc trojkata:  " << t.getWidth() << std::endl;
	std::cout << "Maksymalna warotsc pochodnej:  " << p.maxDerivative(t) << std::endl;
	std::cout << "Roznica min i max wartosci:  " << p.diffreneceBeetwenMinAndMaxValue(t) << std::endl;
}
