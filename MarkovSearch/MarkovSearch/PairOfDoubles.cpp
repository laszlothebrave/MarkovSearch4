#include "pch.h"
#include "PairOfDoubles.h"


PairOfDoubles::PairOfDoubles()
{
	min = DBL_MAX;
	max = DBL_MIN;
}

void PairOfDoubles::addCandidate(const double & candidate)
{
	if (candidate < min) min = candidate;
	if (candidate > max) max = candidate;
}
