#pragma once

class CPiCalculator
{
public:
	CPiCalculator();
	double Calculate(size_t countIterations) const;
private:
	size_t GetCountPointsInCircle(size_t countIterations) const;
	bool IsPointInCircle(CPoint const& point) const;
};