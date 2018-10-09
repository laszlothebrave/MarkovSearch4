#include "pch.h"
#include "Polynomial.h"

//	derivativeNormPolynomial = DerivativeNormPolynomial(4*a*a + e*e, 4*a*b + 2*d*e, 4*c*c + e*e, 2*b*e + 4*c*d, 4*a*e + 4*c*e, b*b + d*d);

Polynomial::Polynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f = 0) : 
	a(a), 
	b(b), 
	c(c), 
	d(d), 
	e(e), 
	f(f)
{
	
}

void Polynomial::createDerivative()
{
	derivativeNormPolynomial = new Polynomial(4 * a*a + e * e, 4 * a*b + 2 * d*e, 4 * c*c + e * e, 2 * b*e + 4 * c*d, 4 * a*e + 4 * c*e, b*b + d * d);
}

const PairOfDoubles& Polynomial::getExtremumOnTriangle(const Triangle & triangle)
{
	PairOfDoubles pairOfDoubles;

	return pairOfDoubles;
}

const PairOfDoubles& Polynomial::getExtremumDerivativeOnTriangle(const Triangle & triangle)
{
	return derivativeNormPolynomial->getExtremumOnTriangle(triangle);
}

Polynomial::~Polynomial()
{
	delete derivativeNormPolynomial;
}

double Polynomial::valueAtPoint(const Point & p)
{
	// TO DO dfsdfsdfsdfsdfsdfdsfsdf
	return 0.0;
}
