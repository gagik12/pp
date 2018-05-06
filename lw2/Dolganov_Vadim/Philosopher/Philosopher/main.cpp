#include "stdafx.h"
#include "Fork.h"
#include "Philosopher.h"
#include "Thread.h"
#include "ThreadHandler.h"

//óòèëèòû äëÿ ñîçäàíèÿ îáúåêòîâ
namespace ObjectÑreatorUtils
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

int main()
{
	try
	{
		CFork::Forks forks = ObjectÑreatorUtils::CreateForks();
		CPhilosopher::PhilosophersPtr philosophers = ObjectÑreatorUtils::CreatePhilosophers();

		CThreadHandler::ThreadHandlerPtr threadHandler = ObjectÑreatorUtils::CreateThreadHandler(philosophers);
		threadHandler->Execute();

	}
	catch (std::exception const& exception)
	{
		std::cout << exception.what() << std::endl;
	}
    return 0;
}

