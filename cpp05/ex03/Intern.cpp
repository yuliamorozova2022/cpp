#include "Intern.h"

const std::string Intern::_forms[3] = {"shrubbery request", "robotomy request", "presidential request"};

//---------------- Orthodox Canonical Form ----------------
Intern::Intern() {
	std::cout << "Default Intern created" << std::endl;
}

Intern::Intern(const Intern& orig) {
	(void)orig;
	std::cout << "Copy constructor. Intern copied" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator = (const Intern& orig) {
	if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. Intern assigned" << std::endl;
	return *this;
}
//--------------------------------

AForm *Intern::newShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::newRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}
AForm *Intern::newPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

//---------------- exceptions ----------------
const char* Intern::UnknownType::what() const throw() {
	return (RED "Unknown type of the form!" NRM);
}
//---------------- methods ------------------
AForm * Intern::makeForm(std::string type, std::string target) {
	int idx = FORMNUMBER;
	for (int i = 0; i < FORMNUMBER; i++) {
		if (type == _forms[i]) {
			idx = i;
			std::cout << "Intern creates " << _forms[i] << std::endl;
			break;
		}
	}
	switch(idx) {
		case 0:
			return newShrubbery(target);
		case 1:
			return newShrubbery(target);
		case 2:
			return newShrubbery(target);
		default:
			throw Intern::UnknownType();
			// std::cerr << "Invalid form type (" << type << ")." << std::endl;
	}
	return NULL;
}