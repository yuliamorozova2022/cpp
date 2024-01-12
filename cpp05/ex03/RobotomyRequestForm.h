#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include "AForm.h"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
//-------- Orthodox Canonical Form ---------
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& orig);
	/*virtual*/ ~RobotomyRequestForm();
	RobotomyRequestForm& operator = (const RobotomyRequestForm& orig);
//------------------------------------------
	RobotomyRequestForm(std::string target);
//---------------- getters -----------------
	std::string getTarget() const;
//---------------- methods ------------------
    void execute(Bureaucrat const & executor) const;
//---------------- attributes ----------------
private:
	const std::string _target;
};

#endif