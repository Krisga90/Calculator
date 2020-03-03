#include <iostream>
#include "variableDouble.h"
#include "equation.h"
#include <regex>



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

	auto temp = primeNumbers();

	std::string str="-a^12+12.34b^11/12=7",str_result;

	std::smatch matches;
	std::regex reg("[=]?([+-]?[\\d]*[.]?[\\d]*)?[*]?([a-zA-Z])[^]?([\\d]*)?[/]?([\\d]*)?");		//matches.str(3) and matches.str(4) prepare for index 
	
	std::vector<Variable> var;
	
	//temp;
	double val, index_n_val, index_d_val;

	char ch;

	while (std::regex_search(str, matches, reg))
	{
		std::cout << "\n" << matches.str(0) << "\n";
		str_result = matches.str(1);
		if ((str_result.size() == 1 && (str_result[0] == '+' || str_result[0] == '-'))||(str_result.size() == 0))
		{
			str_result+="1";
		}
		val = std::stod(str_result);


		str_result = matches.str(3);

		if (str_result.size() > 0)
		{
			index_n_val = std::stod(str_result);
		}
		else if(str_result.size() == 0)
		{
			index_n_val = 1;
			index_d_val = 1;
		}
		str_result = matches.str(4);
		if (str_result.size() > 0)
		{
			index_d_val = std::stod(str_result);
		}
		else if (str_result.size() == 0)
		{
			index_d_val = 1;
		}
		ch = matches.str(2)[0];
		var.push_back(Variable(val, matches.str(2)[0],index_n_val,index_d_val));
		str=matches.suffix().str();
	}

	reg = "[=]?([+-]?[\\d]+[.]?[\\d]*)";
	while (std::regex_search(str, matches, reg))
	{
		std::cout << "\n" << matches.str(0) << "\n";
		if (matches.str().size() > 0)
		{
			var.push_back(Variable(std::stod(matches.str(1))));
		}
		str = matches.suffix().str();

	}

	Equation eq1;
	eq1.assign("1+2x=0");
	Variable var_e1(2, 'x');

	eq1.variable(0) == var_e1;

	int j = 0;
	return 0;


}