
#include "AForm.h"

//---------------- Orthodox Canonical Form ----------------
AForm::AForm() : _name("Form"), _gradeSign(1), _gradeExec(1), _status(false) {
	std::cout << "Default AForm created" << std::endl;
}

/*
	Something weird, because it's not possible to copy or assign constant attributes of the class
*/
AForm::AForm(const AForm& orig) : _name(orig._name), _gradeSign(orig._gradeSign), _gradeExec(orig._gradeExec) {
	_status = orig._status;
	std::cout << "Copy constructor. AForm " << _name << " copied" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm " << _name <<" destroyed" << std::endl;
}

/*
	Something weird, because it's not possible to copy or assign constant attributes of the class
*/
AForm& AForm::operator = (const AForm& orig) {
	if (this == &orig) {
		return *this;
	}
	_status = orig.getStatus();
	std::cout << "Assignment operator. AForm " << _name << " assigned" << std::endl;
	return *this;
}
//--------------------------------
AForm::AForm(std::string name, int sign, int exec) : _name(name), _gradeSign(sign), _gradeExec(exec) {
	if (sign < MAXGRADE || exec < MAXGRADE) {
		throw GradeToHighExeption();
	}
	if (sign > MINGRADE ||exec > MINGRADE) {
		throw GradeToLowExeption();
	}
	_status = false;
	std::cout << "Full AForm constructor. AForm " << _name << " created" << std::endl;
}
//---------------- getters ----------------
std::string AForm::getName() const {
	return _name;
}
int AForm::getGradeSign() const {
	return _gradeSign;
}
int AForm::getGradeExec() const {
	return _gradeExec;
}
bool AForm::getStatus() const {
	return _status;
}
//---------------- methods ----------------

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_status == true) {
		throw AlreadySignedExeption();
	}
	if (bureaucrat.getGrade() > _gradeSign) {
		throw GradeToLowExeption();
	}
	_status = true;
	std::cout << "Bureaucrat " << bureaucrat.getName() << " successfuly signed Form " << _name << "." << std::endl; 
}

//---------------- exceptions ----------------
const char* AForm::GradeToHighExeption::what() const throw() {
	return (RED "Grade is too high!" NRM);
}
const char* AForm::GradeToLowExeption::what() const throw() {
	return (RED "Grade is too low!" NRM);
}
const char* AForm::AlreadySignedExeption::what() const throw() {
	return (YELLOW "Form is already signed!" NRM);
}
const char* AForm::NotSignedExeption::what() const throw() {
	return (YELLOW "Form is not signed yet!" NRM);
}

//---------------- "<<" overload ----------------
std::ostream& operator << (std::ostream &ss, const AForm& form) {
	ss << "Form " << form.getName() << " had grade to sign: " << form.getGradeSign()
	<< ", grade to execute: " << form.getGradeExec() << ", status: ";
	if (form.getStatus()) {
		std::cout << "signed";
	} else {
		std::cout << "not signed";
	}
	std::cout << ".";
	return ss;
}
