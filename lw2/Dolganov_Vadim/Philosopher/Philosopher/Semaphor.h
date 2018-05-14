#pragma once

class Semaphor
{
public:
	Semaphor();

	void Lock();
	void Unlock();
private:
	HANDLE m_hSemaphore;
};