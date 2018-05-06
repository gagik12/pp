#include "stdafx.h"
#include "Philosopher.h"


CPhilosopher::CPhilosopher(std::string const& name)
	: m_name(name)
{
}

void CPhilosopher::SetAvailableForks(AvailableForks const& availableForks)
{
	m_availableForks = availableForks;
}

void CPhilosopher::MainLoop()
{
	while (true)
	{
		m_availableForks.first.Lock(); //����� 1 �����
		m_availableForks.second.Lock(); //����� 2 �����
		std::printf("#%s: Eat noodles\n", m_name.c_str());
		Sleep(1000);
		std::printf("#%s: Put forks\n", m_name.c_str());
		m_availableForks.first.Unlock();
		m_availableForks.second.Unlock();
		std::printf("#%s: Think\n", m_name.c_str());
		Sleep(1500);

	}
}