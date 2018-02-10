#pragma once
#include "Point.h"
#include "IPiCalculator.h"

struct ThreadResult 
{
	size_t countPointsInCircle;
	size_t countIterations;
};

typedef std::vector<ThreadResult> ThreadResults;

class CMultiThreadedPiCalculator : public IPiCalculator
{
public:
	CMultiThreadedPiCalculator(size_t countIterations, size_t countThreads);
	double Calculate() override;
private:
	size_t m_countIterations;
	size_t m_countThreads;

	static DWORD WINAPI GetCountPointsInCircle(LPVOID lpParam);

	void InitThreads();
	void CloseThreads();

	std::vector<HANDLE> m_hThreads;
	std::vector<ThreadResult> m_threadResults;
};
