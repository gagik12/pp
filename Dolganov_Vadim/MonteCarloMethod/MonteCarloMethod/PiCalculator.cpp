#include "stdafx.h"
#include "PiCalculator.h"
#include "Random.h"

const int RADIUS = 1;

CPiCalculator::CPiCalculator(size_t countIterations, size_t countThreads)
	: m_countIterations(countIterations)
	, m_countThreads(countThreads)
{
	InitThreads();
}

void CPiCalculator::InitThreads()
{
	//TODO: упростить
	m_threadResults.assign(m_countThreads, ThreadResult{ 0, m_countIterations / m_countThreads });
	int residueDivision = m_countIterations % m_countThreads;
	for (size_t i = 0; i < m_countThreads; ++i)
	{
		if (residueDivision != 0)
		{
			residueDivision--;
			m_threadResults[i].countIterations++;
		}
	}

	for (size_t i = 0; i < m_countThreads; ++i)
	{
		m_hThreads.push_back(CreateThread(NULL, NULL, &GetCountPointsInCircle, &m_threadResults[i], NULL, NULL));
	}
}

double CPiCalculator::Calculate()
{
	WaitForMultipleObjects(m_hThreads.size(), m_hThreads.data(), TRUE, INFINITE);
	
	size_t countPointsInCircle = std::accumulate(m_threadResults.begin(), m_threadResults.end(), 0, [](int currentCount, ThreadResult const& value) {
		return currentCount + value.countPointsInCircle;
	});

	CloseThreads();
	return 4.0 * countPointsInCircle / m_countIterations;
}

bool CPiCalculator::IsPointInCircle(CPoint const& point)
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= RADIUS;
}

DWORD WINAPI CPiCalculator::GetCountPointsInCircle(LPVOID lpParam)
{
	ThreadResult * threadResult = ((ThreadResult*)lpParam);
	CRandom random(-RADIUS, RADIUS);
	for (size_t i = 0; i < threadResult->countIterations; ++i)
	{
		CPoint point = random.GetPoint();

		if (IsPointInCircle(point))
		{
			++threadResult->countPointsInCircle;
		}
	}
	ExitThread(0);
}

void CPiCalculator::CloseThreads()
{
	for (size_t i = 0; i < m_countThreads; i++) {
		CloseHandle(m_hThreads[i]);
	}
}