#include "BitcoinExchange.hpp"

static std::ifstream checkFile(std::string name, char mode) {
    std::string line;
    std::ifstream file(name.c_str());
    if (file.is_open() == false) {
        std::cerr << "Error: can't open file \"" << name << "\"" << std::endl;
        exit(2);
    }
    std::getline(file, line);
    if ((mode == 'i' && line != "date | value") || (mode == 'd' && line != "date,exchange_rate")) {
        file.close();
        std::cerr << "Error: wrong file \"" << name << "\" formatting" << std::endl;
        exit(3);
    }
    return file;
}

//-------- Orthodox Canonical Form ---------
BitcoinExchange::BitcoinExchange() {
    std::string line;
    std::ifstream db = checkFile("data.csv", 'd');
    // if (db.is_open() == false) {
    //     std::cerr << "Error: can't open file \"data.csv\"" << std::endl;
    //     exit(2);
    // }
    // std::getline(db, line);
    // if (line != "date,exchange_rate") {
    //     db.close();
    //     std::cerr << "Error: wrong file \"data.csv\" formatting" << std::endl;
    //     exit(3);
    // }
    // _values = NULL;
    while (std::getline(db, line)) {
        //TODO
        std::cout << line << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
    db.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& orig) {
	_values = orig._values;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& orig) {
	if (this == &orig) {
		return *this;
	}
	_values = orig._values;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::readFile(std::string path) {
    std::string line;
    std::ifstream infile = checkFile(path, 'i');
    // if (infile.is_open() == false) {
    //     std::cerr << "Error: can't open file \"" << path << "\"" << std::endl;
    //     exit(2);
    // }
    // std::getline(infile, line);
    // if (line != "date | value") {
    //     infile.close();
    //     std::cerr << "Error: wrong file \"" << path << "\" formatting" << std::endl;
    //     exit(3);
    // }
    while (std::getline(infile, line)) {
        //TODO
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
        std::cout << line << std::endl;
    }
    infile.close();
}