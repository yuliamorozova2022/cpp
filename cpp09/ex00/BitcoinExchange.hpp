#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <iostream>
#include <fstream>
#include <map>
// #include <cstdio>

class BitcoinExchange {
public:
//-------- Orthodox Canonical Form ---------
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& orig);
    BitcoinExchange& operator=(const BitcoinExchange& orig);
	~BitcoinExchange();
	void readFile(std::string path);
private:
	std::map <std::string, float> _values;
};

#endif

//exit codes :
//1 - wrong number of arguments
//2 - can't open file
//3 - wrong file format