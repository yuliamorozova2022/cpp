
#ifndef HARL_CPP
#define HARL_CPP

#include <iostream>

class Harl {
    private:
        void debug();
        void info();
        void error();
        void warning();
    public:
        void complain(std::string level);
        Harl();
	    ~Harl();
};

#endif