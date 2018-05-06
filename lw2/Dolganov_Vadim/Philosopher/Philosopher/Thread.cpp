#include "stdafx.h"
#include "Thread.h"

CThread::CThread(Function && function)
	: m_function(std::move(function))
	, m_handle(CreateThread(NULL, 0, &CThread::Start, &m_function, 0, NULL))
{
}

CThread::~CThread()
{
	CloseHandle(m_handle);
}

void CThread::Wait()
{
	WaitForSingleObject(m_handle, INFINITE);
}

//https://stackoverflow.com/a/15192706/6573543
DWORD WINAPI CThread::Start(LPVOID lpParam)
{
	auto fun = reinterpret_cast<Function*>(lpParam);
	(*fun)();
	return 0;
}