#include "BitcoinExchange.hpp"
#include <climits>

static void checkFile(std::string name, char mode) {
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
}

static void checkEmpty(std::string str, bool input) {
	std::string ret;
	if (input) {
		ret = "<Input file> ";
	} else {
		ret = "<database file> ";
	}
	if (str.length() == 0) {
		throw std::invalid_argument(ret + "error: empty value"); 
	}
}

static void checkDate(std::string date, bool input) {	// void BitcoinExchange::checkDate(std::string date) {
	std::string ret;
	if (input) {
		ret = "<Input file> ";
	} else {
		ret = "<database file> ";
	}
	if (date.length() == 0) {
		throw std::invalid_argument(ret + "error: empty date"); 
	}
	if (date.length() != 10 && date[4] != date[7] && date[4] != '-') {
		throw std::invalid_argument(ret + "error: wrong date format => " + date); 
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2022) {
		throw std::invalid_argument(ret + "error: year is out of range => " + date);
	}
	if (month < 1 || month > 12) {
		throw std::invalid_argument(ret + "error: month is out of range => " + date);
	}
	if (month == 2 && ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))) {
		throw std::invalid_argument(ret + "error: day is out of range => " + date);
	}
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		throw std::invalid_argument(ret + "error: day is out of range => " + date);
	}
	if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month ==12)) {
		throw std::invalid_argument(ret + "error: day is out of range => " + date);
	}
}

static void checkVal(float value, bool input) {
	std::string ret;
	if (input) {
		ret = "<Input file> ";
	} else {
		ret = "<database file> ";
	}
	if (value < 0) {
		throw std::invalid_argument(ret + "error: not a positive number");
	}
	if (input && value >1000) {
		throw std::invalid_argument(ret + "error: too large number");
	}
	if (value > __FLT_MAX__) {
		throw std::invalid_argument(ret + "error: too large number");
	}
}

//-------- Orthodox Canonical Form ---------
BitcoinExchange::BitcoinExchange() {
    std::string line;
    checkFile("data.csv", 'd');
	std::ifstream db("data.csv");
	std::getline(db, line);
	// int i = 0;
    while (std::getline(db, line)) {
		try {
			size_t found = line.find_first_of(",");
			// std::cout << ", was found at " << found << std::endl;
			std::string date = line.substr(0, found);
			// std::cout << "date is  " << date << std::endl;
			checkDate(date, false);
			line = line.erase(0, found + 1);
			checkEmpty(line, false);
			// std::cout << "line is  " << line << std::endl;
			float val;
			std::stringstream ss(line);	// Creating a stringstream object
			ss >> val;
			checkVal(val, false);
			// std::cout << "val is  " << val << std::endl;
			_values.insert(std::pair<std::string, float>(date, val));
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
    }
    /* std::cout << "------------------------------" << std::endl;
	std::map<std::string, float>::iterator it = _values.begin();
	i = 0;
	while (it != _values.end()) {
		std::cout << i << "		pair is: " << it->first << " / " << it->second << std::endl;
		it++;
		i++;
	}
	std::cout << "------------------------------" << std::endl; */
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
	checkFile(path, 'i');
	std::ifstream infile(path.c_str());
	std::getline(infile, line);
    while (std::getline(infile, line)) {
        
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
        // std::cout << line << std::endl;
		try {
			size_t found = line.find_first_of("|");
			// std::cout << ", was found at " << found << std::endl;
			std::string date = line.substr(0, found);
			// std::cout << "date is  " << date << std::endl;
			checkDate(date, true);
			line = line.erase(0, found + 1);
			checkEmpty(line, true);
			// std::cout << "line is  " << line << std::endl;
			float val;
			std::stringstream ss(line);// Creating a stringstream object
			ss >> val;
			// std::cout << "before check val is  " << val << std::endl;
			checkVal(val, true);
			// std::cout << "val is  " << val << std::endl;
			
			//TODO
			std::map<std::string, float>::iterator it = _values.lower_bound(date);
			if (it != _values.begin() && it->first != date) {
				it--;
			}
			std::cout << it->first << " => " << val << " = " << val * (it->second) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
    }
    infile.close();
}
