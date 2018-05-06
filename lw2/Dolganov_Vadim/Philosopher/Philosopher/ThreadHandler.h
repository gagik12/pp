#pragma once
#include "Thread.h"

class CThreadHandler
{
public:
	typedef std::unique_ptr<CThreadHandler> ThreadHandlerPtr;

	CThreadHandler();
	~CThreadHandler();
	void AddThread(CThread::ThreadPtr && thread);
	void Execute();
private:
	CThread::ThreadsPtr m_threads;
};