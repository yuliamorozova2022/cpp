#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main() {
	Bureaucrat mr("mr", 5);
	std::cout << "	Bureaucrat:" << std::endl;
	std::cout << mr << std::endl;
	Intern newbe;
	AForm* blank = NULL;

	std::cout << "\n----------------TEST 1-------------------\n" << std::endl;
	std::cout << "	Intern tries to create unknown form:" << std::endl;
	try {
		blank = newbe.makeForm("reward request", "rew");
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----------------TEST 2-------------------\n" << std::endl;
	std::cout << "	Intern tries to create forms:" << std::endl;
	//ShrubberyCreationForm
	try {
		blank = newbe.makeForm("shrubbery request", "shr");
		std::cout << *blank << std::endl;
		blank->beSigned(mr);
		blank->execute(mr);
		delete blank;
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//PresidentialPardonForm
	try {
		blank = newbe.makeForm("presidential request", "pr");
		std::cout << *blank << std::endl;
		blank->beSigned(mr);
		blank->execute(mr);
		delete blank;
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//RobotomyRequestForm
	try {
		blank = newbe.makeForm("robotomy request", "Bender");
		std::cout << *blank << std::endl;
		blank->beSigned(mr);
		blank->execute(mr);
		delete blank;
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}

	return 0;
}