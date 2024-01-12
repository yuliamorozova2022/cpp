#include "PresidentialPardonForm.h"


//-------- Orthodox Canonical Form ---------
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "Default PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& orig) : AForm("PresidentialPardonForm", 25, 5), _target(orig.getTarget()){
    std::cout << "Copy constructor. PresidentialPardonForm " << orig.getName() << " copied" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& orig) {
    if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. PresidentialPardonForm assigned" << std::endl;
	return *this;
}
//------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Full constructor. PresidentialPardonForm created" << std::endl;
}

//---------------- getters ----------------
std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

//---------------- methods ------------------
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (getStatus() == false) {
        throw AForm::NotSignedExeption();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeToLowExeption();
    }
    std::cout << "\t" << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}