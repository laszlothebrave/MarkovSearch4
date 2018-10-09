#pragma once
class PairOfDoubles
{
public:
	double min;
	double max;
	PairOfDoubles() : min(DBL_MAX), max(DBL_MIN) {};
	void addCandidate(const double& candidate) {
		if (candidate < min) min = candidate;
		if (candidate > max) max = candidate;

	}
};

