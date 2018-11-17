#pragma once
#include "pch.h"
#include "Polynomial.h"
#include "Xor128.h"

namespace kkt
{
	Xor128Rng rng{ std::random_device ()(),std::random_device ()() };

	constexpr Polynomial randomPolynomial (const Polynomial& p)
	{
		const double& radius = 8;

		return Polynomial (p.a + rng.nextDouble (-radius, radius),
			p.b + rng.nextDouble (-radius, radius),
			p.c + rng.nextDouble (-radius, radius),
			p.d + rng.nextDouble (-radius, radius),
			p.e + rng.nextDouble (-radius, radius)
		);
	}

	constexpr Triangle randomTriangle (const Triangle& t)
	{
		const double& radius = 8;

		return Triangle (Point(t.p1.x + rng.nextDouble (-radius, radius),
			t.p1.y + rng.nextDouble (-radius, radius)),
			Point(t.p2.x+ rng.nextDouble (-radius, radius),
			t.p2.y + rng.nextDouble (-radius, radius)),
			Point(t.p3.x + rng.nextDouble (-radius, radius),
			t.p3.y + rng.nextDouble (-radius, radius))
		);
	}

	template <class NextCandidateGenerator>
	constexpr Polynomial optimizePolynomial (const Polynomial& startingPolynomial, const Triangle& area, NextCandidateGenerator gen, int iterations = 1000)
	{
		Polynomial bestPolynomial = startingPolynomial;
		Polynomial derivative = startingPolynomial.getDerivative ();

		double dfMax = derivative.extremumOn (area).max;
		double fabsMax = utils::pow2 (startingPolynomial.extremumOn (area).absDifference () / 2);
		double bestVal = dfMax / fabsMax;

		for (int i = 0; i < iterations; ++i)
		{
			const Polynomial candidate = gen (bestPolynomial);
			const Polynomial candidateDerivative = candidate.getDerivative ();
			const MinMaxCandidate candidateExtrema = candidate.extremumOn (area);

			const double fabs = utils::pow2 (candidateExtrema.absDifference () / 2);
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

	template <class NextCandidateGenerator>
	constexpr Triangle optimizeTriangle (const Polynomial& polynomial, const Triangle& startingArea, NextCandidateGenerator gen, int iterations = 1000)
	{
		Triangle bestArea = startingArea;

		Polynomial derivative = polynomial.getDerivative ();

		double dfMax = derivative.extremumOn (bestArea).max;
		double fabsMax = utils::pow2 (polynomial.extremumOn (bestArea).absDifference () / 2);
		double bestVal = dfMax / fabsMax * bestArea.getWidthSquare();

		for (int i = 0; i < iterations; ++i)
		{
			Triangle candidate = gen (bestArea);

			const MinMaxCandidate candidateExtrema = polynomial.extremumOn (candidate);

			const double fabs = utils::pow2 (candidateExtrema.absDifference () / 2);
			const double df = derivative.extremumOn (candidate).max;
			const double val = df / fabs * candidate.getWidthSquare();

			if (val > bestVal)
			{
				bestArea = candidate;
				bestVal = val;
			}
		}

		return bestArea;
	}
}