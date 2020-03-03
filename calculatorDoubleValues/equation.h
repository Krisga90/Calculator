#pragma once
#ifndef EQUATION_H_
#define EQUATION_H_
#include <vector>
#include "variableDouble.h"
#include <string>


class Equation
{
private:
	std::vector<Variable> _variables;
	std::vector<char> _chars;
	void makeequation(std::string str);
	
public:
	Equation() {};
	Equation(std::string str);
	
	void assign(std::string str);
	std::vector<Variable> variables()const;
	Variable variable(int i) { return _variables[i]; }
	Variable constant();
	double constant_d();
	Variable operator[](int i) { return _variables[i]; }
};


#endif // !EQUATION_H_