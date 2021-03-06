#ifndef varCULATE_DOUBLE_H_
#define varCULATE_DOUBLE_H_

#include <iostream>
#include "primeNumbers.h"



#pragma once
class Variable
{
private:
	double _value;
	char _ch;
	int _index_numerator;
	int _index_denominator;

	void fractionShortening();
	void index_divide(const int numerator,const int denominator, char ch);
	void index_multiply(const int numerator, const int denominator, char ch);

public:

	//					***constructors***
	Variable();
	Variable(double val, const char c='0', int index_numerator = 1, int index_denominator = 1);
	Variable(int val, const char c = '0', int index_numerator = 1, int index_denominator = 1);
	Variable(const Variable & var);
	Variable(const char c, int index_numerator = 1, int index_denominator = 1);


	//	END				***constructors***

	Variable & operator=(const Variable & var);

	inline double value() const { return _value; }					//return _value
	inline std::pair<int, int> indexp()const { return std::pair<int, int>(_index_numerator, _index_denominator); }		//return 2 index values
	inline double index()const { return (static_cast<double>(_index_numerator) / static_cast<double>(_index_denominator)); }
	void assign(const double val,char c ='0', int index_numerator=1, int index_denominator = 1);			//assigne _value , char c
	//void assign(const int val, char c= '0', int index_numerator = 1, int index_denominator = 1);				//assigne _value,  char c

	//				*****operators +=,-=,*=,/=*********
	//		******values

	
	Variable & operator+=(double val);	//_value = _value +val;
	Variable & operator-=(double val);	//_value = _value -val;
	Variable & operator*=(double val);	//_value = _value *val;
	Variable & operator/=(double val);	//_value = _value /val;
	

	//		******Class Variable
	Variable & operator+=(const Variable & var);	//_value = _value +var._value;
	Variable & operator-=(const Variable & var);	//_value = _value -var._value;
	Variable & operator*=(const Variable & var);	//_value = _value *var._value;
	Variable & operator/=(const Variable & var);	//_value = _value /var._value;

	//	END			*****operators +=,-=,*=,/=*********

	//				*****operators +,-,*,/*********
	//		******values
	Variable operator+(double val)const;	// =Variable(_value + val);
	Variable operator-(double val)const;	// =Variable(_value - val);
	Variable operator*(double val)const;	// =Variable(_value * val);
	Variable operator/(double val)const;	// =Variable(_value / val);

	//		******Class Variable
	Variable operator+(const Variable & var)const;	// =Variable(_value + var._value);
	Variable operator-(const Variable & var)const;	// =Variable(_value - var._value);
	Variable operator*(const Variable & var)const;	// =Variable(_value * var._value);
	Variable operator/(const Variable & var)const;	// =Variable(_value / var._value);

	bool operator==(const Variable & var)const;


	//				*****FRIEND FUNCTIONS****

	//				*****friend operators +,-,*,/*********
	friend Variable operator+(double val, const Variable & var);	// =Variable(var._value + val);
	friend Variable operator-(double val, const Variable & var);	// =Variable(var._value - val);
	friend Variable operator*(double val, const Variable & var);	// =Variable(var._value * val);
	friend Variable operator/(double val, const Variable & var);	// =Variablevar.(_value / val);
};

#endif // !varCULATE_DOUBLE_H_