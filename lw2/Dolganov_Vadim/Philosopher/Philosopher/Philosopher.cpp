#include "stdafx.h"
#include "Philosopher.h"


CPhilosopher::CPhilosopher(std::string const& name)
	: m_name(name)
{
}

void CPhilosopher::MainLoop()
{
	while (true)
	{
		std::cout << "Maim Loop: " << m_name << std::endl;
		Sleep(1000);
	}
}