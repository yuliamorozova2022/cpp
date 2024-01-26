#include "ScalarConverter.h"

//-------- Orthodox Canonical Form ---------
ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& orig) {
	(void)orig;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& orig) {
	if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

//---------------- methods ------------------
void ScalarConverter::convert(std::string& str) {
	int type = parseString(str);
	// std::cout<< type << std::endl;
	switch (type) {
		case CHAR:
			fromChar(str);
			break;
		case INT:
			fromInt(str);
			break;
		case FLOAT:
			fromFloat(str);
			break;
		case DOUBLE:
			fromDouble(str);
			break;
		default:
			throw InvalidInputException();
	}
}

//---------------- exceptions ----------------
const char* ScalarConverter::InvalidInputException::what() const throw() {
	return (RED "Invalid input! Not possible to convert or print.\n" NRM);
}


//---------------- additional functions ----------------
int parseString(std::string& str) {
	// std::cout<< str << ", length="<<str.length()<<std::endl;
	
	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan") {
		return DOUBLE;
	} else if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf") {
		return FLOAT;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	} else if (isInt(str)) {
		return INT;
	} else if (isChar(str)) {
		return CHAR;
	} else {
		return ERR;
	}
}
//---------------- check funcs ------------------
bool isDouble(std::string& str) {
	int idx = 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() != 1) {
		idx = 1;
	}
	// std::cout << "double start index = " << idx << std::endl;
	if (str.find_first_not_of(DOUBLE_SET, idx) != std::string::npos) {
		return false;
	}
	if (str[idx] == '.' || str[str.length() - 1] == '.') {
		return false;
	}
	if (str.find('.') == std::string::npos || str.find_first_of(".") != str.find_last_of(".")) {
		return false;
	}
	return true;
}

bool isFloat(std::string& str) {
	int idx = 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() != 1) {
		idx = 1;
	}
	// std::cout << "float start index = " << idx << std::endl;
	if (str.find_first_not_of(FLOAT_SET, idx) != std::string::npos) {
		return false;
	}
	if ((str.find_first_of("f") != str.find_last_of("f")) || str[idx] == 'f' || str[str.length() - 1] != 'f') {
		return false;
	}
	if ((str.find_first_of(".") != str.find_last_of(".")) || str[idx] == '.' || str[str.length() - 1] == '.') {
		return false;
	}
	return true;
}

bool isInt(std::string& str) {
	int idx = 0;
	if ((str[0] == '+' || str[0] == '-') && str.length() != 1) {
		idx = 1;
	}
	return (str.find_first_not_of(INT_SET, idx) == std::string::npos);
}

bool isChar(std::string& str) {
	return (str.length() == 1 && std::isprint(str[0]) && std::isdigit(str[0]) == false);
}

//---------------- print funcs ------------------
static void printChar(std::string& str, char a, int i) {
	if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf" || str == "+inf" || str == "inf" || str == "-inf" || str == "nan") {
		std::cout << "char: Impossible" << std::endl;
	} else if (i < 0 || i > UCHAR_MAX) {
		std::cout << "char: Impossible" << std::endl;
	} else if (std::isprint(a)) {
		std::cout << "char: \'" << a << "\'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

static void printInt(std::string& str, long in) {
	if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf" || str == "+inf" || str == "inf" || str == "-inf" || str == "nan") {
		std::cout << "int: Impossible" << std::endl;
	} else if (in < INT_MIN || in > INT_MAX) {
		std::cout << "int: Impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(in) << std::endl;
	}
}

static void printFloat(std::string& str, float in) {
	double check = std::atof(str.c_str());
	if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf") {
		std::cout << "float: " << str << std::endl;
	} else if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan") {
		std::cout << "float: " << str << "f" << std::endl;
	} else if ((check < INT_MIN || check > INT_MAX)) {
		std::cout << "float: Impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << in << "f" << std::endl;
	}
}

static void printDouble(std::string& str, double in) {
	double check = std::atof(str.c_str());
	if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan") {
		std::cout << "double: " << str << std::endl;
	} else if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf") {
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	} else if ((check < INT_MIN || check > INT_MAX)) {
		std::cout << "double: Impossible" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << in << std::endl;
	}
}
//---------------- convert funcs ------------------
void fromChar(std::string& str) {
	char a = static_cast<unsigned char>(str[0]);
	printChar(str, a,  static_cast<int>(a));
	printInt(str, static_cast<int>(a));
	printFloat(str, static_cast<float>(a));
	printDouble(str, static_cast<double>(a));
}

void fromInt(std::string& str) {
	long a = std::atol(str.c_str());
	printChar(str, static_cast<unsigned char>(a), static_cast<int>(a));
	printInt(str, a);
	printFloat(str, static_cast<float>(a));
	printDouble(str, static_cast<double>(a));
}

void fromFloat(std::string& str) {
	float a = std::atof(str.c_str());
	printChar(str, static_cast<unsigned char>(a), static_cast<int>(a));
	printInt(str, static_cast<int>(a));
	printFloat(str, a);
	printDouble(str, static_cast<double>(a));
}

void fromDouble(std::string& str) {
	double a = std::atof(str.c_str());
	printChar(str, static_cast<unsigned char>(a), static_cast<int>(a));
	printInt(str, static_cast<int>(a));
	printFloat(str, static_cast<float>(a));
	printDouble(str, static_cast<double>(a));
}
