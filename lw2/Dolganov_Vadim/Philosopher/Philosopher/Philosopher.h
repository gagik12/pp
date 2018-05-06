#pragma once
class CPhilosopher
{
public:
	typedef std::unique_ptr<CPhilosopher> PhilosopherPtr;
	typedef std::vector<PhilosopherPtr> PhilosophersPtr;

	CPhilosopher(std::string const& name);
	void MainLoop();
private:
	std::string m_name;
};

