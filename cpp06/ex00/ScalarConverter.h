#ifndef __SCALARCONVERTER__
#define __SCALARCONVERTER__

#include <iostream>
#include <iomanip>
#include <limits>
#include <exception>
#include <cctype>
#include <cstdlib>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

class ScalarConverter {
public:
//---------------- methods ------------------
	static void convert(std::string& str);
	class InvalidInputException : public std::exception {
		const char* what() const throw();
	};
private:
//-------- Orthodox Canonical Form ---------
	ScalarConverter();
	ScalarConverter(const ScalarConverter& orig);
	/*virtual*/ ~ScalarConverter();
	ScalarConverter& operator = (const ScalarConverter& orig);

};

#define ERR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

#define INT_SET "0123456789"
#define FLOAT_SET "0123456789.f"
#define DOUBLE_SET "0123456789."

int parseString(std::string& str);
bool isDouble(std::string& str);
bool isFloat(std::string& str);
bool isInt(std::string& str);
bool isChar(std::string& str);
void fromChar(std::string& str);
void fromInt(std::string& str);
void fromFloat(std::string& str);
void fromDouble(std::string& str);


#endif