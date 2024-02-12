#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <fstream>
#include <iostream>
#include <map>
#include <algorithm> // std::remove_if
#include <cstdlib>
// #include <string>
#include <sstream>
#include <exception>
// #include <cstdio>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"


class BitcoinExchange {
public:
//-------- Orthodox Canonical Form ---------
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& orig);
	BitcoinExchange& operator=(const BitcoinExchange& orig);
	~BitcoinExchange();
	void readFile(std::string path);
	// void checkDate(std::string date);
	//---------------- exceptions ---------------
	// class ErrorDateException : public std::exception {
	// 	virtual const char* what(std::string str) const throw();
	// };

private:
	std::map <std::string, float> _values;
};

#endif

//exit codes :
//1 - wrong number of arguments
//2 - can't open file
//3 - wrong file format