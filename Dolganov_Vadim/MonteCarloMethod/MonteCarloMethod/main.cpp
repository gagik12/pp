#include "stdafx.h"
#include "PiCalculator.h"

const int MAX_ARGUMENT_COUNT = 3;
const std::string ERROR_MESSAGE = "Invalid arguments count\nUsage: MonteCarloMethod.exe <Count Iterations> <Count Threads>";

int main(int argc, char *argv[])
{
	try
	{
		if (argc != MAX_ARGUMENT_COUNT)
		{
			throw std::invalid_argument(ERROR_MESSAGE);
		}

		size_t countIterations = std::stoi(argv[1]);
		size_t countThreads = std::stoi(argv[2]);

		unsigned int startTime = clock();
		CPiCalculator piCalculator(countIterations, countThreads);
		std::cout << "Result: " << piCalculator.Calculate() << std::endl;
		unsigned int endTime = clock();
		std::cout << "Time: " << (static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC) << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}

