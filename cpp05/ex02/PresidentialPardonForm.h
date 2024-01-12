#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__

#include "AForm.h"

class PresidentialPardonForm : public AForm {
public:
//-------- Orthodox Canonical Form ---------
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& orig);
	/*virtual*/ ~PresidentialPardonForm();
	PresidentialPardonForm& operator = (const PresidentialPardonForm& orig);
//------------------------------------------
	PresidentialPardonForm(std::string target);
//---------------- getters -----------------
	std::string getTarget() const;
//---------------- methods ------------------
    void execute(Bureaucrat const & executor) const;
//---------------- attributes ----------------
private:
	const std::string _target;
};

#endif