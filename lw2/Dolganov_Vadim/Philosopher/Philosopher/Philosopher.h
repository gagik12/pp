#pragma once
#include "Fork.h"

class CPhilosopher
{
public:
	typedef std::unique_ptr<CPhilosopher> PhilosopherPtr;
	typedef std::vector<PhilosopherPtr> PhilosophersPtr;

	typedef std::pair<CFork, CFork> AvailableForks;

	CPhilosopher(std::string const& name);
	void MainLoop();
	void SetAvailableForks(AvailableForks const& availableForks);
private:
	std::string m_name;
	AvailableForks m_availableForks;
};

