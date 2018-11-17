#pragma once
#include "pch.h"
#include "Polynomial.h"
#include "Xor128.h"

namespace kkt
{
	Xor128Rng rng;

	constexpr Polynomial randomPolynomial (const Polynomial& p, const double& radius = 10)
	{
		return Polynomial (p.a + rng.nextDouble (-radius, radius),
			p.b + rng.nextDouble (-radius, radius),
			p.c + rng.nextDouble (-radius, radius),
			p.d + rng.nextDouble (-radius, radius),
			p.e + rng.nextDouble (-radius, radius)
		);
	}

	template <class NextCandidateGenerator>
	constexpr Polynomial optimizePolynomial (const Polynomial& startingPolynomial, const Triangle& area, NextCandidateGenerator gen, int iterations = 1000)
	{
		Polynomial bestPolynomial = startingPolynomial;
		Polynomial derivative = startingPolynomial.getDerivative ();

		double dfMax = derivative.extremumOn (area).max;
		double fabsMax = startingPolynomial.extremumOn (area).absDifference () / 4;
		double bestVal = fabsMax / dfMax;

		for (int i = 0; i < iterations; ++i)
		{
			Polynomial candidate = gen (bestPolynomial);
			Polynomial candidateDerivative = candidate.getDerivative ();
			MinMaxCandidate candidateExtrema = candidate.extremumOn (area);

			const double df = candidateExtrema.absDifference () / 4;
			const double fabs = candidateDerivative.extremumOn (area).max;
			const double val = fabs / df;

			if (val > bestVal)
			{
				bestPolynomial = candidate;
				bestPolynomial.f = -(candidateExtrema.max + candidateExtrema.min) / 4;
				bestVal = val;
			}
		}

		return bestPolynomial;
	}
}