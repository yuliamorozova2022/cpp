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

    for (int i = 0; i < 4; i++) {
        if (levels[i].compare(level) == 0) {
            (this->*(func[i]))();
        }
    }
}
