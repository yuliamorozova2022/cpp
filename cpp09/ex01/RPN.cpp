#include "RPN.hpp"
//-------- Orthodox Canonical Form ---------
RPN::RPN() {
	// _dev0 = false;
}
RPN::RPN(const RPN& orig) {
	_stackInt = orig._stackInt;
	// _stackOpers = orig._stackOpers;
	// _dev0 = false;
}
RPN& RPN::operator=(const RPN& orig) {
	if (this == &orig) {
		return *this;
	}
	_stackInt = orig._stackInt;
	// _stackOpers = orig._stackOpers;
	// _dev0 = false;
	return *this;
}
RPN::~RPN() {
}

//---------------- exceptions ----------------
const char* RPN::ErrorException::what() const throw() {
	return (RED "Error.\n" NRM);
}
const char* RPN::DevByZeroException::what() const throw() {
	return (RED "Error. Devided by 0\n" NRM);
}
const char* RPN::UnknownCharacterException::what() const throw() {
	return (RED "Error. Unknown character\n" NRM);
}
//------------------------------------------

void RPN::calculate(char c) {
	if (c == ' ') {
		return;
	}
	if (_stackInt.size() > 1) {
		int num2 = _stackInt.top();
		_stackInt.pop();
		int num1 = _stackInt.top();
		_stackInt.pop();
		if (c == '+') {
			_stackInt.push(num1 + num2);
		} else if (c == '-') {
			_stackInt.push(num1 - num2);
		} else if (c == '*') {
			_stackInt.push(num1 * num2);
		} else if (c == '/') {
			if (num2 != 0) {
				_stackInt.push(num1 / num2);
			} else {
				throw DevByZeroException();
			}
		}
		//  else {
		// 	throw UnknownCharacterException();
		// }
	} else {
		throw ErrorException();
	}
}

int RPN::handle(const char *str) {
// 	std::cout << "str: " << str << std::endl;
	int i =0;
	while (str[i]) {
		if (isdigit(str[i])) {
			_stackInt.push(str[i] - '0');
		} else if (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			calculate(str[i]);
		} else {
			throw UnknownCharacterException();
		}
		i++;
	}
	if (_stackInt.size() == 1) {
		return _stackInt.top();
	} else {
		throw ErrorException();
	}
}





/*
void RPN::fillStacks(char *str) {
	// try {
		int i = -1;
		while (str[++i]) {
			std::cout << "char = " << str[i] << std::endl;
			if (isdigit(str[i])) {
				_stackInt.push(str[i] - '0');
				std::cout << "push _stackInt" << std::endl;
			} else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
				_stackOpers.push(str[i]);
				std::cout << "push _stackOpers" << std::endl;
			} else if (str[i] == ' ') {
				continue;
			} else {
				throw "Error: unknown simbol";
			}
		}
		std::cout << "end of filling" << std::endl;
	// }
	// catch(std::exception& e) {
	// 	std::cerr << e.what() << std::endl;
	// }
}

void RPN::calcPushRes(int a, int b, char sign) {
	if (sign == '+')
		_stackInt.push(a + b);
	if (sign == '-')
		_stackInt.push(a - b);
	if (sign == '*')
		_stackInt.push(a * b);
	if (sign == '/') {
		if (b != 0) {
			_stackInt.push(a / b);
		} else {
			_dev0 = true;
			_stackInt.push(0);
		}
		// 	throw "Error: devide by 0";
	}
}

void RPN::calculate() {
	int num1, num2;
	char oper;
	if (_stackInt.size() > 1) {
		while (_stackInt.size() != 1 && _stackOpers.size() != 0) {
			num2 = _stackInt.top();
			_stackInt.pop();
			num1 = _stackInt.top();
			_stackInt.pop();
			oper = _stackOpers.top();
			_stackOpers.pop();
			calcPushRes(num1, num2, oper);
			if (_stackInt.top() == 0 && _dev0 == true) {
				throw "Error: devide by 0";
			}
		}
	}
	else
		throw "Error: only one number in stack";
}

int RPN::handle(char *str) {
	std::cout << "str: " << str << std::endl;
	fillStacks(str);
	calculate();
	if (_stackInt.size() == 1) {
		return _stackInt.top();
	} else {
		throw "Error";
	}
}
*/