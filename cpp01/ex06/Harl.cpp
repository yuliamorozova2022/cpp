#include "Harl.h"

Harl::Harl() {
    ;
}
Harl::~Harl() {
    ;
}

void Harl::debug() {
    std::cout << "[DEBUG] " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[INFO] " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error() {
    std::cout << "[ERROR] " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::warning() {
    std::cout << "[WARNING] "<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::complain(std::string level) {

    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;

    while(levels[i].compare(level) && i < 4) {
        i++;
    }
    switch(i) {
        case 0:
            (this->*(func[0]))();
            std::cout << std::endl;
        case 1:
            (this->*(func[1]))();
            std::cout << std::endl;
        case 2:
            (this->*(func[2]))();
            std::cout << std::endl;
        case 3:
            (this->*(func[3]))();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
    }
}