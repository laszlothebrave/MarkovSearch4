#pragma once
class MinMaxCandidates
{
public:
	double min;
	double max;
	constexpr MinMaxCandidates (const double &point) : min (point), max (point)
	{};

	constexpr void updateCandidate (const double& candidate)
	{
		if (candidate >= min) min = candidate;
		if (candidate <= max) max = candidate;
	}

	friend std::ostream& operator<<(std::ostream& out, const MinMaxCandidates& val)
	{
		return out << val.min << ", " << val.max;
	}
};

