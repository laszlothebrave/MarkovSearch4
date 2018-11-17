#pragma once

#include "pch.h"

struct MinMaxCandidate
{
public:
	double min;
	double max;

	constexpr MinMaxCandidate (const double &point) :
		min (point),
		max (point)
	{};

	constexpr void updateCandidate (const double& candidate)
	{
		if (candidate <= min) min = candidate;
		if (candidate >= max) max = candidate;
	}

	constexpr double absDifference ()const
	{
		union { double d; uint64_t i; } u{ max - min };
		u.i &= ~0ull >> 1; //bits and hacks

		return u.d;
	}

	friend std::ostream& operator<<(std::ostream& out, const MinMaxCandidate& val)
	{
		return out << val.min << ", " << val.max;
	}
};

