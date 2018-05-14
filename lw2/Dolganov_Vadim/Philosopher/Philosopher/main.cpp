#include "stdafx.h"
#include "Fork.h"
#include "Philosopher.h"
#include "Thread.h"
#include "ThreadHandler.h"

//утилиты для создания объектов
namespace ObjectCreatorUtils
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

//Усадить философов по местам
//У конкретного философа слева и справа на столе лежат вилки
//Aristotle вилка с индексом 0 и 1
//Socrates вилка с индексом 1 и 2
//Pifagor вилка с индексом 2 и 3
//Platon вилка с индексом 3 и 4
//Ptolemy вилка с индексом 4 и 0
void InitPhilosophersWithForks(CFork::Forks const& forks, CPhilosopher::PhilosophersPtr & philosophers)
{
	for (size_t i = 0; i < CFork::MAX_COUNT_FORKS; ++i)
	{
		size_t nextForkIndex = (i + 1) % CFork::MAX_COUNT_FORKS;
		philosophers[i]->SetAvailableForks(std::make_pair(forks[i], forks[nextForkIndex]));
	}
}

int main()
{
	try
	{
		CFork::Forks forks = ObjectCreatorUtils::CreateForks();
		CPhilosopher::PhilosophersPtr philosophers = ObjectCreatorUtils::CreatePhilosophers();
		InitPhilosophersWithForks(forks, philosophers);
		CThreadHandler::ThreadHandlerPtr threadHandler = ObjectCreatorUtils::CreateThreadHandler(philosophers);
		threadHandler->Execute();

	}
	catch (std::exception const& exception)
	{
		std::cout << exception.what() << std::endl;
	}
    return 0;
}

