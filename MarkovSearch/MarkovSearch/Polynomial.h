#pragma once
#include "DerivativeNormPolynomial.h"
#include "Triangle.h"
#include "vector"
#include "PairOfDoubles.h"
class Polynomial
{
private:
	double a, b, c, d, e, f;

public:
	//Polynomial form: a*x^2 + b*x + c*y^2 + d*y + e*x*y + f
	Polynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f);
	const Polynomial& createDerivative();
	const PairOfDoubles& getExtremumOnTriangle(const Triangle& triangle);
	double valueAtPoint(const Point& p);
};

