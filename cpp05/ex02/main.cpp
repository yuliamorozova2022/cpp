#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main() {
	Bureaucrat mr("mr", 5);
	std::cout << "	Bureaucrat:" << std::endl;
	std::cout << mr << std::endl;
	std::cout << "\n----------------TEST 1-------------------\n" << std::endl;
	ShrubberyCreationForm scform("scform");
	std::cout << "	ShrubberyCreationForm:" << std::endl;
	std::cout << scform << std::endl;
	RobotomyRequestForm rrform("rrform");
	std::cout << "	RobotomyRequestForm:" << std::endl;
	std::cout << rrform << std::endl;
	PresidentialPardonForm ppform("ppform");
	std::cout << "	PresidentialPardonForm:" << std::endl;
	std::cout << ppform << std::endl;
	std::cout << "	Bureaucrat tries to execute forms that are not signed:" << std::endl;
	//ShrubberyCreationForm
	try {
		std::cout << "	Bureaucrat tries to execute ShrubberyCreationForm" << std::endl;
		scform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//RobotomyRequestForm
	try {
		std::cout << "	Bureaucrat tries to execute RobotomyRequestForm" << std::endl;
		rrform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//PresidentialPardonForm
	try {
		std::cout << "	Bureaucrat tries to execute PresidentialPardonForm" << std::endl;
		ppform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}

	scform.beSigned(mr);
	rrform.beSigned(mr);
	ppform.beSigned(mr);

	std::cout << "\n----------------TEST 2-------------------\n" << std::endl;
	mr.decreaseGrade(141);
	std::cout << "	Bureaucrat tries to execute signed forms with too low grade:" << std::endl;
	//ShrubberyCreationForm
	try {
		std::cout << "	Bureaucrat tries to execute ShrubberyCreationForm" << std::endl;
		scform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//RobotomyRequestForm
	try {
		std::cout << "	Bureaucrat tries to execute RobotomyRequestForm" << std::endl;
		rrform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//PresidentialPardonForm
	try {
		std::cout << "	Bureaucrat tries to execute PresidentialPardonForm" << std::endl;
		ppform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	///*
	std::cout << "\n----------------TEST 3-------------------\n" << std::endl;
	mr.increaseGrade(141);
	std::cout << "	Bureaucrat tries to execute forms that are signed:" << std::endl;
	//ShrubberyCreationForm
	try {
		scform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//RobotomyRequestForm
	try {
		rrform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//PresidentialPardonForm
	try {
		ppform.execute(mr);
	}
	catch (std::exception& e) {
		std::cerr  << "Exception: " << e.what() << std::endl;
	}
	//*/
	return 0;
}