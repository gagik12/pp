#pragma once
#include "Point.h"
#include "Random.h"

class CMonteCarloMethod
{
public:
	CMonteCarloMethod(int countIterations);
	double Calculate();
	bool IsPointInCircle(CPoint const& point);
	size_t GetCountPointsInCircle(int countIterations);
private:
	size_t m_countIterations;
	std::shared_ptr<CRandom> m_random;
	int m_countPointInCircle = 0;
};

