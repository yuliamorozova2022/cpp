#include "ShrubberyCreationForm.h"

//-------- Orthodox Canonical Form ---------
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "Default ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& orig) : AForm("ShrubberyCreationForm", 145, 137), _target(orig.getTarget()){
    std::cout << "Copy constructor. ShrubberyCreationForm " << orig.getName() << " copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& orig) {
    if (this == &orig) {
		return *this;
	}
	std::cout << "Assignment operator. ShrubberyCreationForm assigned" << std::endl;
	return *this;
}
//------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Full constructor. ShrubberyCreationForm created" << std::endl;
}

//---------------- getters ----------------
std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

//---------------- methods ------------------
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (getStatus() == false) {
        throw AForm::NotSignedExeption();
    } else if (executor.getGrade() > getGradeExec()) {
        throw AForm::GradeToLowExeption();
    } else {
		std::ofstream outfile;
		outfile.open((_target + "_shrubbery").c_str(), std::ios::out);
		if (!outfile.is_open()) {
			std::cerr << "Error, can't open outfile" << std::endl;
			return;
		}
		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			std::endl;
		}
		outfile.close();
	}
}