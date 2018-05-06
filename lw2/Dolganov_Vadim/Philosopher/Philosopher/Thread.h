#pragma once

typedef std::function<void()> Function;

class CThread
{
public:
	CThread(Function && function);
	~CThread();
	void Wait();
private:
	HANDLE m_handle;
	Function m_function;
	static DWORD WINAPI Start(LPVOID lpParam);
};

