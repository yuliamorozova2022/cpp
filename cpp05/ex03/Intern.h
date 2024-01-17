#ifndef __INTERN__
#define __INTERN__

// #include <exception>
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

#define FORMNUMBER 3

class Intern {
public:
//-------- Orthodox Canonical Form ---------
	Intern();
	Intern(const Intern& orig);
	/*virtual*/ ~Intern();
	Intern& operator = (const Intern& orig);

//---------------- getters -----------------
    int getFormNumber(std::string type);
//---------------- methods ------------------
    AForm *makeForm(std::string type, std::string target);
//---------------- exceptions ----------------
class UnknownType : public std::exception {
		const char* what() const throw();
};
//---------------- attributes ----------------
private:
	static const std::string _forms[FORMNUMBER];
    AForm *newShrubbery(std::string target);
    AForm *newRobotomy(std::string target);
    AForm *newPresidential(std::string target);
};

typedef AForm* (Intern::*func_pointers)(std::string target);

#endif