#pragma once
class MinMaxCandidates
{
public:
	double min;
	double max;
	constexpr MinMaxCandidates() : min(DBL_MAX), max(DBL_MIN) {};

	constexpr void updateCandidate(const double& candidate) 
	{
		if (candidate < min) min = candidate;
		if (candidate > max) max = candidate;
	}
};

