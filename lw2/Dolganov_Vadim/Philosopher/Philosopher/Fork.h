#pragma once
#include "Semaphor.h"

class CFork : public Semaphor
{
public:
	typedef std::vector<CFork> Forks;
	static const int MAX_COUNT_FORKS = 5;
	CFork();
};

