#include "RPN.hpp"
#include <string>

int main(int argc, char *argv[]) {
	
		if (argc != 2) {
			// printErr();
			std::cerr << "Error. Usage: ./RPN \"reverse polish notation expression\"" << std::endl;
			return 1;
		//wrong input
		}
		if (std::string(argv[1]) == "test") {
			try {
				std::cout << "Examples from the task " << std::endl;
				RPN n1;
				const char *str1 = "8 9 * 9 - 9 - 9 - 4 - 1 +";
				std::cout << "res for \"" << str1 << "\" is " << n1.handle(str1) << std::endl;
				RPN n2;
				const char *str2 = "7 7 * 7 -";
				std::cout << "res for \"" << str2 << "\" is " << n2.handle(str2) << std::endl;
				RPN n3;
				const char *str3 = "1 2 * 2 / 2 * 2 4 - +";
				std::cout << "res for \"" << str3 << "\" is " << n3.handle(str3) << std::endl;
				//fail:
				RPN n4;
				const char *str4 = "(1 + 1)";
				std::cout << "res for \"" << str4 << "\" is " << n4.handle(str4) << std::endl;
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
			try {
				std::cout << "Additional examples" << std::endl;
				RPN n1;
				const char *str1 = "3 5 6 + *";
				std::cout << "res for \"" << str1 << "\" is " << n1.handle(str1) << std::endl;// result must be 33
				RPN n2;
				const char *str2 = "2 4 / 8 6 - *"; // = (2 / 4) * (8 - 6)
				std::cout << "res for \"" << str2 << "\" is " << n2.handle(str2) << std::endl;// result must be -0.5 or in that case 0
				
				RPN n3;
				const char *str3 = "3 7 + 2 / 5 * 6 8 - 2 * - ";
				std::cout << "res for \"" << str3 << "\" is " << n3.handle(str3) << std::endl;// result must be 29
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
		else {
			try {
				RPN n;
				std::cout << n.handle(argv[1]) << std::endl;
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
		
	

	return 0;
}