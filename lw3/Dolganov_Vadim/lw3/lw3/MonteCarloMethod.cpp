#include "stdafx.h"
#include "MonteCarloMethod.h"

static const int RADIUS = 1; 

CMonteCarloMethod::CMonteCarloMethod(int countIterations)
	: m_countIterations(countIterations)
	, m_random(std::make_shared<CRandom>(-RADIUS, RADIUS))
{
}

double CMonteCarloMethod::Calculate()
{
	int countPointsInCircle = GetCountPointsInCircle(m_countIterations);
	return 4.0 * countPointsInCircle / m_countIterations;
}

bool CMonteCarloMethod::IsPointInCircle(CPoint const& point)
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= RADIUS;
}

size_t CMonteCarloMethod::GetCountPointsInCircle(int countIterations)
{
	#pragma omp parallel for
	for (int i = 0; i < countIterations; ++i)
	{
		CPoint point = m_random->GetPoint();

		if (IsPointInCircle(point))
		{
			#pragma omp atomic
			++m_countPointInCircle;
		}
	}
	return m_countPointInCircle;
}