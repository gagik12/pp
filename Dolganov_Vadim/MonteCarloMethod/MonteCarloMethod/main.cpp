#include "stdafx.h"
#include "PiCalculator.h"

const int MAX_ARGUMENT_COUNT = 3;
const int MIN_ARGUMENT_COUNT = 2;
const std::string HELP_OPTION = "--help";
const std::string ERROR_MESSAGE = "Invalid arguments count\n";
const std::string HELP_MESSAGE = "Usage: MonteCarloMethod.exe <Count Iterations> <Count Threads>";

int main(int argc, char *argv[])
{
	if ((argc == MIN_ARGUMENT_COUNT) && (argv[1] == HELP_OPTION))
	{
		std::cout << HELP_MESSAGE << std::endl;
		return 1;
	}
	try
	{
		if (argc != MAX_ARGUMENT_COUNT)
		{
			throw std::invalid_argument(ERROR_MESSAGE + HELP_MESSAGE);
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

