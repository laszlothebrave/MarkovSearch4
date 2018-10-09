#pragma once
#include "Polynomial.h"
class PolynomialAndDerivativePack
{
private:
	Polynomial polynomial;
	Polynomial derivative;
public:
	PolynomialAndDerivativePack(const Polynomial& polynomial);
};

