#ifndef __RPN__
#define __RPN__

#include <iostream>
#include <exception>
#include <stack>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

class RPN {
public:
//-------- Orthodox Canonical Form ---------
	RPN();
	RPN(const RPN& orig);
	RPN& operator=(const RPN& orig);
	~RPN();
//---------------- methods ----------------
	int handle(const char *str);
//---------------- exceptions ---------------
	class ErrorException : public std::exception {
		const char* what() const throw();
	};
	class DevByZeroException : public std::exception {
		const char* what() const throw();
	};
	class UnknownCharacterException : public std::exception {
		const char* what() const throw();
	};

private:
	std::stack<int> _stackInt;
	// void calculate();
	void calculate(char c);
};

#endif