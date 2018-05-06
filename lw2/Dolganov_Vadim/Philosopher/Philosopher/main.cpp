#include "stdafx.h"
#include "Fork.h"
#include "Philosopher.h"

//������� ��� �������� ��������
namespace Object�reatorUtils
{
	CFork::Forks CreateForks()
	{
		CFork::Forks forks;
		for (size_t i = 0; i < CFork::MAX_COUNT_FORKS; ++i)
		{
			forks.push_back(CFork());
		}
		return forks;
	}

	CPhilosopher::PhilosophersPtr CreatePhilosophers()
	{
		CPhilosopher::PhilosophersPtr philosophers;
		philosophers.push_back(std::make_unique<CPhilosopher>("Aristotle"));
		philosophers.push_back(std::make_unique<CPhilosopher>("Socrates"));
		philosophers.push_back(std::make_unique<CPhilosopher>("Pifagor"));
		philosophers.push_back(std::make_unique<CPhilosopher>("Platon"));
		philosophers.push_back(std::make_unique<CPhilosopher>("Ptolemy"));

		return philosophers;
	}
}

int main()
{
	try
	{
		CFork::Forks forks = Object�reatorUtils::CreateForks();
		CPhilosopher::PhilosophersPtr philosophers = Object�reatorUtils::CreatePhilosophers();
	}
	catch (std::exception const& exception)
	{
		std::cout << exception.what() << std::endl;
	}
    return 0;
}

