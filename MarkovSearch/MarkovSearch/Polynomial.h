#pragma once
#include "DerivativeNormPolynomial.h"
#include "Triangle.h"
#include "vector"
#include "MinMaxCandidates.h"
class Polynomial
{
private:
	double a, b, c, d, e, f;

public:
	//Polynomial form: a*x^2 + b*x + c*y^2 + d*y + e*x*y + f

	constexpr Polynomial (const double& a, const double& b, const double& c, const double& d, const double& e, const double& f = 0) :
		a (a), b (b), c (c), d (d), e (e), f (f)
	{}

	constexpr Polynomial createDerivative () const
	{
		return Polynomial (4 * a*a + e * e, 4 * a*b + 2 * d*e, 4 * c*c + e * e, 2 * b*e + 4 * c*d, 4 * a*e + 4 * c*e, b*b + d * d);
	}

	constexpr double operator()(const double& x, const double& y) const
	{
		return a * x*x + b * x + c * y*y + d * y + e * x*y + f;
	}

	constexpr double operator()(const Point& p) const
	{
		return operator()(p.x, p.y);
	}

	constexpr double valueAtPoint (const Point& p) const
	{
		return operator()(p);
	}

	MinMaxCandidates getExtremaOnTriangle (const Triangle& triangle) const
	{
		auto [P1, P2, P3] = triangle.getPoints ();	
		MinMaxCandidates pairOfDoubles;

		pairOfDoubles.updateCandidate (valueAtPoint (P1));
		pairOfDoubles.updateCandidate (valueAtPoint (P2));
		pairOfDoubles.updateCandidate (valueAtPoint (P3));

		return pairOfDoubles;
	}
};