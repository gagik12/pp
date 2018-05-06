#include "stdafx.h"
#include "Fork.h"
#include "Philosopher.h"
#include "Thread.h"
#include "ThreadHandler.h"

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

	CThreadHandler::ThreadHandlerPtr CreateThreadHandler(CPhilosopher::PhilosophersPtr & philosophers)
	{
		CThreadHandler::ThreadHandlerPtr threadHandler = std::make_unique<CThreadHandler>();
		for (auto & philosopher : philosophers)
		{
			threadHandler->AddThread(std::make_unique<CThread>([&philosopher]() {
				philosopher->MainLoop();
			}));
		}
		return threadHandler;
	}

}

//������� ��������� �� ������
//� ����������� �������� ����� � ������ �� ����� ����� �����
//Aristotle ����� � �������� 0 � 1
//Socrates ����� � �������� 1 � 2
//Pifagor ����� � �������� 2 � 3
//Platon ����� � �������� 3 � 4
//Ptolemy ����� � �������� 4 � 0
void ToSeatPhilosophersInPlaces(CFork::Forks const& forks, CPhilosopher::PhilosophersPtr & philosophers)
{
	for (size_t i = 0; i < CFork::MAX_COUNT_FORKS; ++i)
	{
		philosophers[i]->SetAvailableForks(std::make_pair(forks[i], forks[(i + 1) % CFork::MAX_COUNT_FORKS]));
	}
}

int main()
{
	try
	{
		CFork::Forks forks = Object�reatorUtils::CreateForks();
		CPhilosopher::PhilosophersPtr philosophers = Object�reatorUtils::CreatePhilosophers();
		ToSeatPhilosophersInPlaces(forks, philosophers);
		CThreadHandler::ThreadHandlerPtr threadHandler = Object�reatorUtils::CreateThreadHandler(philosophers);
		threadHandler->Execute();

	}
	catch (std::exception const& exception)
	{
		std::cout << exception.what() << std::endl;
	}
    return 0;
}

