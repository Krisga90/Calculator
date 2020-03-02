
#include <fstream>
#include "primeNumbers.h"
#include <string>


std::string sFileName = "primeNumbers.txt";
char cNumberSeparator = ' ';

//void my_generate_prime_numbers(const int size);
// file separator is " "

std::vector<unsigned int>  generate_prime_numbers(const int largestNumber)
{
	std::vector<unsigned int> vPrimes;
	vPrimes.push_back(2);
	vPrimes.push_back(3);
	int j = 2, icheck_number = 4;
	int i;
	while (icheck_number < largestNumber)
	{
		bool is_prime = 1;
		i = 0;
		icheck_number++;
		while (is_prime)
		{
			if (!(icheck_number % vPrimes[i]))
			{
				is_prime = 0;
			}
			i++;
			if (i >= j)
			{
				break;
			}
		}

		if (is_prime)
		{
			vPrimes.push_back(icheck_number);
			j++;
		}
	}

	std::ofstream fout(sFileName.c_str());
	for (auto y : vPrimes) {
		fout << y << cNumberSeparator;
	}
	fout.close();
	fout.clear();
	return vPrimes;
}

std::vector<unsigned int> primeNumbers()
{
	std::ifstream fin(sFileName.c_str());
	std::vector<unsigned int> vPrimes;
	if (fin.is_open())
	{
		unsigned int iPrime;
		while (fin >> iPrime)
		{
			vPrimes.push_back(iPrime);
		}
		fin.close();
		fin.clear();
	}
	else {
		fin.close();
		fin.clear();
		vPrimes=generate_prime_numbers(1000);
	}
	return vPrimes;
}



