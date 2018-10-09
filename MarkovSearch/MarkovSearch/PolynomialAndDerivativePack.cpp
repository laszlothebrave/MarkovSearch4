#include "pch.h"
#include "PolynomialAndDerivativePack.h"

PolynomialAndDerivativePack::PolynomialAndDerivativePack(const Polynomial& polynomial)
{
	PolynomialAndDerivativePack::polynomial = polynomial;
	derivative = polynomial.createDerivative();
}
