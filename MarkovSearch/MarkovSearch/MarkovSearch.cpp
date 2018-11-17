// MarkovSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Polynomial.h"
#include "Xor128.h"
#include "KKT.h"
#include <bitset>

int main ()
{
	Triangle t (Point (-0.2, -0.1), Point (2, 5), Point (5, 0));
	Polynomial p (10,10,10,10,10);
	Polynomial b = p;

	for (int i = 0; i < 10; ++i)
	{
		p = kkt::optimizePolynomial (p, t, 10);
	}

	std::cout << "Extrema: " << p.extremumOn (t) << '\n';
	std::cout << "Najmniejsza wysokosc trojkata:  " << t.getWidth () << std::endl;
	std::cout << p.extremumOn (t).absDifference () << '\n';
	p.printCtorForm ();
	std::bitset<64> ccc(~(0ull));
	std::cout << ccc << '\n';
	std::cout << p << '\n';

}
