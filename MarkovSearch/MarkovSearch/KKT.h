#pragma once
#include "pch.h"
#include "Polynomial.h"
#include "Xor128.h"

namespace kkt
{
	Xor128Rng rng;

	constexpr Polynomial randomPolynomial (const Polynomial& p)
	{
		const double& radius = 10;

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
		double fabsMax = utils::pow2(startingPolynomial.extremumOn (area).absDifference () / 2);
		double bestVal = dfMax / fabsMax;

		for (int i = 0; i < iterations; ++i)
		{
			const Polynomial candidate = gen (bestPolynomial);
			const Polynomial candidateDerivative = candidate.getDerivative ();
			const MinMaxCandidate candidateExtrema = candidate.extremumOn (area);

			const double fabs = utils::pow2(candidateExtrema.absDifference () / 2);
			const double df = candidateDerivative.extremumOn (area).max;
			const double val = df / fabs;

			if (val > bestVal)
			{
				bestPolynomial = candidate;
				bestPolynomial.f = -(candidateExtrema.max + candidateExtrema.min) / 2;
				bestVal = val;
			}
		}

		return bestPolynomial;
	}
}