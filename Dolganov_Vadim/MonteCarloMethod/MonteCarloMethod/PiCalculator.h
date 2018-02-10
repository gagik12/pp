#pragma once
#include "Point.h"

struct ThreadResult 
{
	size_t countPointsInCircle;
	size_t countIterations;
};

typedef std::vector<ThreadResult> ThreadResults;

class CPiCalculator
{
public:
	CPiCalculator(size_t countIterations, size_t countThreads);
	double Calculate();
private:
	size_t m_countIterations;
	size_t m_countThreads;

	static DWORD WINAPI GetCountPointsInCircle(LPVOID lpParam);
	static bool IsPointInCircle(CPoint const& point);
	void InitThreads();
	void CloseThreads();

	std::vector<HANDLE> m_hThreads;
	std::vector<ThreadResult> m_threadResults;
};
