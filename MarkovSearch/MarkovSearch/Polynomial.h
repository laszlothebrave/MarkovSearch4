#pragma once
#include "DerivativeNormPolynomial.h"
#include "Triangle.h"
#include "vector"
#include "MinMaxCandidate.h"

//x1<=x2<=x3 || x3<=x2<=x1
constexpr bool inline areOrdered (const double& x1, const double& x2, const double& x3)
{
	return x3 <= x2 == x2 <= x1;
}

//p2 on [p1,p3]
constexpr bool inline isOnInterval (const Point& p1, const Point& p2, const Point& p3)
{
	return areOrdered (p1.x, p2.x, p3.x) && areOrdered (p1.y, p2.y, p3.y);
}

//a*x^2 + b*x + c*y^2 + d*y + e*x*y + f
struct Polynomial
{
	double a, b, c, d, e, f;

	//Polynomial form: a*x^2 + b*x + c*y^2 + d*y + e*x*y + f
	constexpr Polynomial (const double a, const double b, const double c, const double d, const double e, const double f = 0) :
		a (a), b (b), c (c), d (d), e (e), f (f)
	{}

	//DerivativeNormPolynomial(4*a*a + e*e, 4*a*b + 2*d*e, 4*c*c + e*e, 2*b*e + 4*c*d, 4*a*e + 4*c*e, b*b + d*d);
	constexpr Polynomial getDerivative () const
	{
		return Polynomial (4 * a*a + e * e, 4 * a*b + 2 * d*e, 4 * c*c + e * e, 2 * b*e + 4 * c*d, 4 * a*e + 4 * c*e, b*b + d * d);
	}

	constexpr inline double operator()(const double x, const double y) const
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

	constexpr MinMaxCandidate extremumOn (const Triangle& triangle) const
	{
		const auto& p1 = triangle.p1,
			p2 = triangle.p2,
			p3 = triangle.p3;

		const auto& l1 = triangle.l1,
			l2 = triangle.l2,
			l3 = triangle.l3;

		MinMaxCandidate minMax (valueAtPoint (p1));
		minMax.updateCandidate (valueAtPoint (p2));
		minMax.updateCandidate (valueAtPoint (p3));

		{
			Point p = getExtremumOnLine (l1);
			if (isOnInterval (p1, p, p2))
				minMax.updateCandidate (valueAtPoint (p));
		}
		{
			Point p = getExtremumOnLine (l2);
			if (isOnInterval (p2, p, p3))
				minMax.updateCandidate (valueAtPoint (p));
		}
		{
			Point p = getExtremumOnLine (l3);
			if (isOnInterval (p1, p, p3))
				minMax.updateCandidate (valueAtPoint (p));
		}
		{
			Point p = getGlobalExtremum ();
			if (triangle.contains (p))
				minMax.updateCandidate (valueAtPoint (p));
		}

		return minMax;
	}

	constexpr Point getExtremumOnLine (const Line& line) const
	{
		const double denominator = 2 * (c*line.a*line.a - e * line.a*line.b + a * line.b*line.b);
		const double x = ((d*line.a*line.b) - (b*line.b*line.b) - (2 * c*line.a*line.c) + (e*line.b*line.c)) / denominator;
		const double y = (-(d*line.a*line.a) + (b*line.a*line.b) + (e*line.a*line.c) - (2 * a*line.b*line.c)) / denominator;

		return Point (x, y);
	}

	constexpr Point getGlobalExtremum () const
	{
		const double x = (-2 * b*c + d * e) / (4 * a*c - e * e);
		const double y = (2 * a*d - b * e) / (4 * a*c - e * e);

		return Point (x, y);
	}

	void printCtorForm ()const
	{
		std::printf ("%.5f,%.5f,%.5f,%.5f,%.5f,%.5f\n", a, b, c, d, e, f);
	}

	friend std::ostream& operator<<(std::ostream& out, const Polynomial& val)
	{
		return out << val.a << " x^2 + " << val.b << " x + " << val.c << " y^2 + " << val.d << " y + " << val.e << " x*y + " << val.f;
	}
};