#include "Bureaucrat.h"
#include "Form.h"

int main() {
	std::cout << "\n-----------------------------------------\n" << std::endl;
	Bureaucrat test1 = Bureaucrat("Test1", 2);
	std::cout << "First bureaucrat (test1):\n" << "	" << test1 << std::endl;
	Form form1 = Form("Form1", 5, 5);
	std::cout << "First form (form1):\n" << "	" << form1 << std::endl;

	std::cout << "\n----------------TEST 1-------------------\n" << std::endl;
	try {
		std::cout << "	test1 should try to sign form1:" << std::endl;
		form1.beSigned(test1);
		std::cout << "	Should fail create form_1:" << std::endl;
		Form form = Form("Form_to_fail", 176, 35);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n----------------TEST 2-------------------\n" << std::endl;
	std::cout << "	Should successfully create form2:" << std::endl;
	Form form2 = Form("Form2", 1, 35);
	try {
		std::cout << "	Should fail sign form2:" << std::endl;
		form2.beSigned(test1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-----------------------------------------\n" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\n----------------TEST 3-------------------\n" << std::endl;
	try {
		std::cout << "	Should fail sign form1:" << std::endl;
		form1.beSigned(test1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----------------TEST 4-------------------\n" << std::endl;
	test1.increaseGrade(1);
	try {
		std::cout << "	Should sign form2:" << std::endl;
		test1.signForm(form2);
		std::cout << "	Should fail sign form1:" << std::endl;
		test1.signForm(form1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n-----------------------------------------\n" << std::endl;
	return 0;
}