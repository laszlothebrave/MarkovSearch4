#pragma once
#include "Polynomial.h"
class PolynomialAndDerivativePack
{
private:
	Polynomial polynomial;
	Polynomial derivative;

public:
	PolynomialAndDerivativePack(const Polynomial& polynomial);
	double maxDerivative(Triangle triangle);
	double diffreneceBeetwenMinAndMaxValue(Triangle triangle);
};

