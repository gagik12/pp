#pragma once

typedef std::function<void()> Function;

class CThread
{
public:
	typedef std::unique_ptr<CThread> ThreadPtr;
	typedef std::vector<ThreadPtr> ThreadsPtr;

	CThread(Function && function);
	~CThread();
	void Wait();
private:
	HANDLE m_handle;
	Function m_function;
	static DWORD WINAPI Start(LPVOID lpParam);
};

