#include "pch.h"
#include "Polynomial.h"

//	derivativeNormPolynomial = DerivativeNormPolynomial(4*a*a + e*e, 4*a*b + 2*d*e, 4*c*c + e*e, 2*b*e + 4*c*d, 4*a*e + 4*c*e, b*b + d*d);

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f) :
	a(a), 
	b(b), 
	c(c), 
	d(d), 
	e(e), 
	f(f)
{
	
}

const Polynomial Polynomial::createDerivative() const
{
	return Polynomial(4 * a*a + e * e, 4 * a*b + 2 * d*e, 4 * c*c + e * e, 2 * b*e + 4 * c*d, 4 * a*e + 4 * c*e, b*b + d * d);
}

const PairOfDoubles Polynomial::getExtremumOnTriangle(const Triangle & triangle) const
{
	PairOfDoubles pairOfDoubles;
	pairOfDoubles.addCandidate(valueAtPoint(triangle.getPoint1()));
	pairOfDoubles.addCandidate(valueAtPoint(triangle.getPoint2()));
	pairOfDoubles.addCandidate(valueAtPoint(triangle.getPoint3()));

	return pairOfDoubles;
}

double Polynomial::valueAtPoint(const Point & p) const
{	
	// a*p.x*p.x + b*p.x + c*p.y*p.y + d*p.y + e*p.x*p.y + f;
	return a*p.x*p.x + b*p.x + c*p.y*p.y + d*p.y + e*p.x*p.y + f;
}
