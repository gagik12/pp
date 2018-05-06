#include "stdafx.h"
#include "ThreadHandler.h"

CThreadHandler::CThreadHandler()
{
}

CThreadHandler::~CThreadHandler()
{
	for (auto & thread : m_threads)
	{
		thread->~CThread();
	}
}

void CThreadHandler::AddThread(CThread::ThreadPtr && thread)
{
	m_threads.push_back(std::move(thread));
}

void CThreadHandler::Execute()
{
	for (auto & thread : m_threads)
	{
		thread->Wait();
	}
}