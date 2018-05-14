#include "stdafx.h"
#include "Semaphor.h"

//CreateSemaphore(nil, 1, 1, nil)  создает семафор с которым может работать только один поток, это равносильно mutex'у
//https://exelab.ru/pro/cpp.php?r=vcppnet&d=zart182
Semaphor::Semaphor()
	: m_hSemaphore(CreateSemaphore(NULL, 1, 1, NULL))
{
}

void Semaphor::Lock()
{
	WaitForSingleObject(m_hSemaphore, INFINITE);
}

void Semaphor::Unlock()
{
	ReleaseSemaphore(m_hSemaphore, 1, NULL);
}