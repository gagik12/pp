#include "stdafx.h"
#include "MonteCarloMethod.h"

const int MAX_ARGUMENT_COUNT = 2;
const std::string ERROR_MESSAGE = "Invalid arguments count\n";
const std::string HELP_MESSAGE = "Usage: lw3.exe <Count Iterations>";

int main(int argc, char *argv[])
{
	try
	{
		if (argc != MAX_ARGUMENT_COUNT)
		{
			throw std::invalid_argument(ERROR_MESSAGE + HELP_MESSAGE);
		}
		
		int countIterations = std::stoi(argv[1]);

		unsigned int startTime = clock();
		CMonteCarloMethod monteCarloMethod(countIterations);
		std::cout << "Result: " << monteCarloMethod.Calculate() << std::endl;
		unsigned int endTime = clock();
		std::cout << "Time: " << (static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}

