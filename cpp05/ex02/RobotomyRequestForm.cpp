#include "RobotomyRequestForm.h"


//-------- Orthodox Canonical Form ---------
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "Default RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& orig) : AForm("RobotomyRequestForm", 72, 45), _target(orig.getTarget()){
    std::cout << "Copy constructor. RobotomyRequestForm " << orig.getName() << " copied" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& orig) {
    if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. RobotomyRequestForm assigned" << std::endl;
	return *this;
}
//------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Full constructor. RobotomyRequestForm created" << std::endl;
}

//---------------- getters ----------------
std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

//---------------- methods ------------------
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (getStatus() == false) {
        throw AForm::NotSignedExeption();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeToLowExeption();
    }
    std::cout << "\t**Makes some drilling noises.**" << std::endl;
    srand((unsigned) time(NULL));
    if (std::rand() % 2 == 0) {
		std::cout << getTarget() << " has been robotomized successfully " << std::endl;
	} else {
		std::cout << "Robotomy Failed." << std::endl;
	}
}