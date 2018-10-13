#pragma once
#include "DerivativeNormPolynomial.h"
#include "Triangle.h"
#include "vector"
#include "MinMaxCandidates.h"

//x1<=x2<=x3 || x3<=x2<=x1
constexpr bool areOrdered (const double& x1, const double& x2, const double& x3)
{
	return x3 <= x2 && x2 <= x2 || x1 <= x2 && x2 <= x3;
}

struct Polynomial
{
	double a, b, c, d, e, f;

	//Polynomial form: a*x^2 + b*x + c*y^2 + d*y + e*x*y + f
	constexpr Polynomial (const double& a, const double& b, const double& c, const double& d, const double& e, const double& f = 0) :
		a (a), b (b), c (c), d (d), e (e), f (f)
	{}

	//DerivativeNormPolynomial(4*a*a + e*e, 4*a*b + 2*d*e, 4*c*c + e*e, 2*b*e + 4*c*d, 4*a*e + 4*c*e, b*b + d*d);
	constexpr Polynomial getGradientNormCube () const
	{
		return Polynomial (4 * a*a + e * e, 4 * a*b + 2 * d*e, 4 * c*c + e * e, 2 * b*e + 4 * c*d, 4 * a*e + 4 * c*e, b*b + d * d);
	}

	constexpr inline double operator()(const double& x, const double& y) const
	{
		return a * x*x + b * x + c * y*y + d * y + e * x*y + f;
	}

	constexpr inline double operator()(const Point& p) const
	{
		return operator()(p.x, p.y);
	}

	constexpr inline double valueAtPoint (const double& x, const double& y) const
	{
		return operator()(x, y);
	}

	constexpr inline double valueAtPoint (const Point& p) const
	{
		return operator()(p);
	}

	constexpr MinMaxCandidates getExtremaOnTriangle (const Triangle& triangle) const
	{
		const auto&[P1, P2, P3] = triangle.getPoints ();
		const auto&[L1, L2, L3] = triangle.getLines ();

		MinMaxCandidates minMax (valueAtPoint (P1));
		minMax.updateCandidate (valueAtPoint (P2));
		minMax.updateCandidate (valueAtPoint (P3));

		minMax.updateCandidate (getExtremumOnLine (L1, P1, P2));
		minMax.updateCandidate (getExtremumOnLine (L2, P2, P3));
		minMax.updateCandidate (getExtremumOnLine (L3, P1, P3));

		minMax.updateCandidate (getGlobalExtremum (triangle));

		return minMax;
	}

	constexpr double getExtremumOnLine (const Line& line, const Point& P1, const Point& P2)const
	{
		const double denominator = 2 * (c*line.a*line.a - e * line.a*line.b + a * line.b*line.b);
		const double x = ((d*line.a*line.b) - (b*line.b*line.b) - (2 * c*line.a*line.c) + (e*line.b*line.c)) / denominator;
		const double y = (-(d*line.a*line.a) + (b*line.a*line.b) + (e*line.a*line.c) - (2 * a*line.b*line.c)) / denominator;

		if (areOrdered (P1.x, x, P2.x) && areOrdered (P1.y, y, P2.y))
			return valueAtPoint (x, y);

		return NAN;
	}

	constexpr double getGlobalExtremum (const Triangle& t) const
	{
		const double x = (-2 * b*c + d * e) / (4 * a*c - e * e);
		const double y = (2 * a*d - b * e) / (4 * a*c - e * e);

		if (t.contains (x, y))
			return valueAtPoint (x, y);

		return NAN;
	}

	friend std::ostream& operator<<(std::ostream& out, const Polynomial& val)
	{
		return out << val.a << " x^2 + " << val.b << " x + " << val.c << " y^2 + " << val.d << " y + " << val.e << " x*y + " << val.f;
	}
};