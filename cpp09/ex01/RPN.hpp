#ifndef __RPN__
#define __RPN__

#include <iostream>
#include <exception>
#include <stack>

// void printErr() {
//     std::cerr << "Error" << std::endl;
// }

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

// #define OPERS "+-*/"
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
    // std::stack<char> _stackOpers;
    // bool _dev0;
    void calculate();
    void calculate(char c);
    // void calcPushRes(int a, int b, char sign);
    // void fillStacks(char *str);
};

#endif