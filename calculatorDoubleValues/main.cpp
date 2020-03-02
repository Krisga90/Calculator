#include <iostream>
#include "variableDouble.h"
//#include "primeNumbers.h"

int main()
{
	Variable via1;
	Variable via2;
	via1.assign(1, 'a',1,2);
	via2.assign(2, 'a',1,3);
	Variable via;
	try {
		via = via1 + via2;
	}
	catch (const std::invalid_argument e)
	{
		std::cerr << e.what();
	}
	int j = 0;
	auto temp = primeNumbers();
	return 0;


}