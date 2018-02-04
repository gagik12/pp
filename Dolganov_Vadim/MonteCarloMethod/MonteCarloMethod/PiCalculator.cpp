#include "stdafx.h"
#include "PiCalculator.h"
#include "Random.h"

const int RADIUS = 1;

CPiCalculator::CPiCalculator()
{
}

double CPiCalculator::Calculate(size_t countIterations) const
{
	size_t countPointsInCircle = GetCountPointsInCircle(countIterations);
	return 4.0 * countPointsInCircle / countIterations;
}

bool CPiCalculator::IsPointInCircle(CPoint const& point) const
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= RADIUS;
}

size_t CPiCalculator::GetCountPointsInCircle(size_t countIterations) const
{
	CRandom random(-RADIUS, RADIUS);

	size_t countPointsInCircle = 0;
	for (size_t i = 0; i < countIterations; ++i)
	{
		CPoint point = random.GetPoint();

		if (IsPointInCircle(point))
		{
			++countPointsInCircle;
		}
	}

	return countPointsInCircle;
}