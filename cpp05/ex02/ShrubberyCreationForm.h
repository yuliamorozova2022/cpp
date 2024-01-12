#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include "AForm.h"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
//-------- Orthodox Canonical Form ---------
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& orig);
	/*virtual*/ ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& orig);
//------------------------------------------
	ShrubberyCreationForm(std::string target);
//---------------- getters -----------------
	std::string getTarget() const;
//---------------- methods ------------------
    void execute(Bureaucrat const & executor) const;
//---------------- attributes ----------------
private:
	const std::string _target;
};

#endif