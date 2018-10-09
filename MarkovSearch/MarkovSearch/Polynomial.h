#pragma once
#include "DerivativeNormPolynomial.h"
#include "Triangle.h"
#include "vector"
#include "PairOfDoubles.h"
class Polynomial
{
private:
	double a, b, c, d, e, f;
	Polynomial *derivativeNormPolynomial;

public:
	//Polynomial form: a*x^2 + b*x + c*y^2 + d*y + e*x*y + f
	Polynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f);
	void createDerivative();
	const PairOfDoubles& getExtremumOnTriangle(const Triangle& triangle);
	const PairOfDoubles& getExtremumDerivativeOnTriangle(const Triangle& triangle);
	virtual ~Polynomial();
	double valueAtPoint(const Point& p);
};

