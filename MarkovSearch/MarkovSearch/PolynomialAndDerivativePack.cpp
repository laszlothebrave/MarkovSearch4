#include "pch.h"
#include "PolynomialAndDerivativePack.h"

PolynomialAndDerivativePack::PolynomialAndDerivativePack(const Polynomial& polynomial)
{
	PolynomialAndDerivativePack::polynomial = polynomial;
	derivative = polynomial.createDerivative();

}

double PolynomialAndDerivativePack::maxDerivative(Triangle triangle)
{
	return derivative.getExtremumOnTriangle(triangle).max;
}

double PolynomialAndDerivativePack::diffreneceBeetwenMinAndMaxValue(Triangle triangle)
{
	PairOfDoubles extremes = derivative.getExtremumOnTriangle(triangle);
	return extremes.max - extremes.min;
}
