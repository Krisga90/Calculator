#include "equation.h"
#include <algorithm>
#include <regex>


//			**********Constructor
Equation::Equation(std::string str)
{
	makeequation(str);
}

// END		**********Constructor
//			**********Private methods
void Equation::makeequation(std::string str)
{
	if (str.size() == 0)
	{
		throw std::invalid_argument("Empty string");
	}
	std::smatch matches;
	std::regex reg("([+-]?[\\d]*[.]?[\\d]*)?[*]?([a-zA-Z])[\\^]?([\\d]*)?[/]?([\\d]*)?");		//matches.str(3) and matches.str(4) prepare for index 
	std::string temp;
	double val, index_n_val, index_d_val;

	while (std::regex_search(str, matches, reg))
	{
		std::cout << "\n" << matches.str(0) << "\n";
		temp = matches.str(1);
		if ((temp.size() == 1 && (temp[0] == '+' || temp[0] == '-')) || (temp.size() == 0))
		{
			temp += "1";
		}
		val = std::stod(temp);


		temp = matches.str(3);

		if (temp.size() > 0)
		{
			index_n_val = std::stod(temp);
		}
		else if (temp.size() == 0)
		{
			index_n_val = 1;
			index_d_val = 1;
		}

		temp = matches.str(4);
		if (temp.size() > 0)
		{
			index_d_val = std::stod(temp);
		}
		else if (temp.size() == 0)
		{
			index_d_val = 1;
		}
		_variables.push_back(Variable(val, matches.str(2)[0], index_n_val, index_d_val));
		str = matches.suffix().str();
	}

	reg = "[=]?([+-]?[\\d]+[.]?[\\d]*)";
	while (std::regex_search(str, matches, reg))
	{
		std::cout << "\n" << matches.str(0) << "\n";
		if (matches.str().size() > 0)
		{
			_variables.push_back(Variable(std::stod(matches.str(1))));
		}
		str = matches.suffix().str();
	}

}

// END		**********Private methods



void Equation::assign(std::string str)
{
	makeequation(str);
}


std::vector<Variable> Equation::variables()const
{
	std::vector<Variable> temp;
	if (_variables.size() > 0)
	{
		std::for_each(_variables.begin(), _variables.end() - 1, [&temp](Variable var) {temp.push_back(var); });
	}
	return temp;
}

Variable Equation::constant()
{
	if (_variables.size() > 0)
	{
		return _variables[_variables.size() - 1];
	}
	else
	{
		throw std::invalid_argument("object is empty");
	}
	
}

double Equation::constant_d()
{
	if (_variables.size() > 0)
	{
		return _variables[_variables.size() - 1].value();
	}
	else
	{
		throw std::invalid_argument("object is empty");
	}
}