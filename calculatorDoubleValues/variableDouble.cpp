#include "variableDouble.h"


//					***constructors***
Variable::Variable() :_value(0), _ch('0'),
_index_numerator(1), _index_denominator(1)
{

}

Variable::Variable(double val, const char c , int index_numerator, int index_denominator) : _value(val), _ch(c),
_index_numerator(index_numerator), _index_denominator(index_denominator)
{

}

Variable::Variable(int val, const char c, int index_numerator, int index_denominator): _ch(c),
_index_numerator(index_numerator), _index_denominator(index_denominator)
{
	_value = static_cast<double>(val);
}

Variable::Variable(const Variable & var) : _value(var._value), _ch(var._ch), 
_index_numerator(var._index_numerator), _index_denominator(var._index_denominator)
{

}

Variable::Variable(const char c, int index_numerator, int index_denominator): _value(1), _ch(c),
_index_numerator(index_numerator), _index_denominator(index_denominator)
{

}




//	END				***constructors***
//				********* private methods
void Variable::fractionShortening()
{

}
//	END			********* private methods

//					***assignment operator***
Variable & Variable::operator=(const Variable & var)
{
	if (&var == this)
	{
		return *this;
	}
	this-> _value = var._value;
	return *this;
}

//	END				***assignment operator***

//					***Return Value***
double Variable::value() const
{
	return _value;
}
//	END				***Return Value***

//			***assign value ***
void Variable::assign(const double val, char c , int index_numerator, int index_denominator)
{
	_value = val;
	_ch = c;
	_index_denominator = index_denominator;
	_index_numerator = index_numerator;

}



/*
void Variable::assign(const int val, char c , int index_numerator, int index_denominator)
{
	_value = static_cast<double>(val);
	_ch = c;
	_index_denominator = index_denominator;
	_index_numerator = index_numerator;
}
*/

//	END				***assign value ***


//				*****operators +=,-=,*=,/=*********
//			***values***


Variable & Variable::operator+=(double val)
{
	if ('0' != _ch)
	{
		throw std::invalid_argument("cant add number to variable ");
	}
	_value += val;
	return *this;
}

Variable & Variable::operator-=(double val)
{
	if ('0' != _ch)
	{
		throw std::invalid_argument("cant subtract number from variable ");
	}
	_value -= val;
	return *this;
}

Variable & Variable::operator*=(double val)
{
	_value *= val;
	return *this;
}

Variable & Variable::operator/=(double val)
{
	if (0 == val)
	{
		throw std::invalid_argument("Can't divide by 0\n");
	}
	_value /= val;
	return *this;
}



//		******Class Variable

Variable & Variable::operator+=(const Variable & var)
{
	if (var._ch!= _ch || (var._index_numerator/var._index_denominator)!=(_index_numerator/_index_denominator))
	{
		throw std::invalid_argument("can't add different variable ");
	}
	_value +=var._value;
	return *this;
}

Variable & Variable::operator-=(const Variable & var)
{
	if (var._ch != _ch || (var._index_numerator / var._index_denominator) != (_index_numerator / _index_denominator))
	{
		throw std::invalid_argument("can't subtract different variable ");
	}
	_value -= var._value;
	return *this;
}

Variable & Variable::operator*=(const Variable & var)
{
	if (var._ch != _ch && (0 !=_index_numerator || 0 != var._index_numerator))
	{
		throw std::invalid_argument("can't multiply different variable ");
	}
	_value *= var._value;
	if (0 == _index_numerator)
	{
		_ch = var._ch;
		_index_denominator = var._index_denominator;
		_index_numerator =   var._index_numerator;
	}
	else if (0 == var._index_numerator)
	{
		//do nothing
	}
	else if (_index_denominator != var._index_denominator)
	{
		_index_denominator *= var._index_denominator;
		_index_numerator = _index_numerator * var._index_denominator + var._index_numerator *_index_denominator;
	}
	else
	{
		_index_numerator += var._index_numerator;
	}
	return *this;
}


Variable & Variable::operator/=(const Variable & var)
{
	if (0 == var._value)
	{
		throw std::invalid_argument("Can't divide by 0\n");
	}
	if (var._ch != _ch && (0 != _index_numerator || 0 != var._index_numerator))
	{
		throw std::invalid_argument("can't divide different variable ");
	}
	_value /= var._value;


	//////////////

	if (0 == _index_numerator)
	{
		_ch = var._ch;
		_index_denominator = var._index_denominator;
		_index_numerator = -var._index_numerator;
	}
	else if (0 == var._index_numerator)
	{
		//do nothing
	}
	else if (_index_denominator != var._index_denominator)
	{
		_index_denominator *= var._index_denominator;
		_index_numerator = _index_numerator * var._index_denominator - var._index_numerator *_index_denominator;
	}
	else
	{
		_index_numerator -= var._index_numerator;
	}

	if (_ch == '0')
	{
		_index_numerator = 1;
		_index_denominator = 1;
	}

	/////////////
	return *this;
}



//    END			*****operators +=,-=,*=,/=*********


//				*****operators +,-,*,/*********

Variable Variable::operator+(double val)const
{
	if ('0' != _ch)
	{
		throw std::invalid_argument("cant add number to variable ");
	}
	return _value + val;
}

Variable Variable::operator-(double val)const
{
	if ('0' != _ch)
	{
		throw std::invalid_argument("cant add number to variable ");
	}
	return _value - val;
}

Variable Variable::operator*(double val)const
{
	return _value * val;
}

Variable Variable::operator/(double val)const
{
	if (0 == val)
	{
		throw std::invalid_argument("Can't divide by 0\n");
	}
	return _value / val;
}


//		******Class Variable
Variable Variable::operator+(const Variable & var)const	// =Variable(_value + var._value);
{
	if (var._ch != _ch || (var._index_numerator / var._index_denominator) != (_index_numerator / _index_denominator))
	{
		throw std::invalid_argument("can't add different variable ");
	}
	return _value + var._value;
}

Variable Variable::operator-(const Variable & var)const	// =Variable(_value - var._value);
{
	if (var._ch != _ch || (var._index_numerator / var._index_denominator) != (_index_numerator / _index_denominator))
	{
		throw std::invalid_argument("can't subtract different variable ");
	}
	return _value - var._value;
}
Variable Variable::operator*(const Variable & var)const	// =Variable(_value * var._value);
{
	Variable temp(*this);
	temp *= var;
	return temp;
}
Variable Variable::operator/(const Variable & var)const	// =Variable(_value / var._value);
{
	if (0 == var._value)
	{
		throw std::invalid_argument("Can't divide by 0\n");
	}
	Variable temp(*this);
	temp /= var;
	return temp;
}


//				*****FRIEND FUNCTIONS****

//				*****friend operators +,-,*,/*********
Variable operator+(double val, const Variable & var)	// =Variable(_value + val);
{
	return var + val;
}

Variable operator-(double val, const Variable & var)	// =Variable(_value - val);
{
	Variable temp(val);
	temp -= var;
	return temp;
}

Variable operator*(double val, const Variable & var)	// =Variable(_value * val)
{
	return var * val;
}

Variable operator/(double val, const Variable & var)	// =Variable(_value / val)
{
	Variable temp(val);
	temp /= var;
	return temp;
}