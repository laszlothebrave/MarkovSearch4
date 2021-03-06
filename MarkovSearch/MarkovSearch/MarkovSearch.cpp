// MarkovSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Polynomial.h"
#include "Xor128.h"
#include "KKT.h"
#include <bitset>
#include <chrono>

int main ()
{
	auto start = std::chrono::high_resolution_clock::now ();
	Triangle t (Point (-0.2, -0.1), Point (2, 5), Point (5, 0));
	Polynomial p (10, 10, 10, 10, 10);

	for (int i = 0; i < 250; ++i)
	{
		p = kkt::optimizePolynomial (p, t, kkt::randomPolynomial, 20000);
		t = kkt::optimizeTriangle(p, t, kkt::randomTriangle, 20000);
		p = kkt::optimizePolynomial (p, t, kkt::randomPolynomial, 20000);
	}

	std::cout << p << '\n' << t << '\n';
	std::cout << "F extrema: " << p.extremumOn (t) << '\n';
	std::cout << "Df extrema: " << p.getDerivative ().extremumOn (t) << '\n';

	double f = p.extremumOn(t).absDifference () / 2;
	double df = std::sqrt (p.getDerivative ().extremumOn (t).max);
	std::cout << "K: " << df / f * t.getWidth () / 4 << '\n';

	std::cout << "Najmniejsza wysokosc trojkata:  " << t.getWidth () << std::endl;
	std::cout << p.extremumOn (t).absDifference () << '\n';
	p.printCtorForm ();
	auto time = std::chrono::duration<double> (std::chrono::high_resolution_clock::now () - start).count ();
	std::cout << "Took: " << time << "s\n";
}
