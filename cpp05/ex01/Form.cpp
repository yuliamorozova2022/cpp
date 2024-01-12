
#include "Form.h"
//---------------- Orthodox Canonical form ----------------
Form::Form() : _name("Form"), _gradeSign(1), _gradeExec(1), _status(false) {
	std::cout << "Default Form created" << std::endl;
}
/*
	Something weird, because it's not possible to copy or assign constant attributes of the class
*/
Form::Form(const Form& orig) : _name(orig._name), _gradeSign(orig._gradeSign), _gradeExec(orig._gradeExec) {
	_status = orig._status;
	std::cout << "Copy constructor. Form " << _name << " copied" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << _name <<" destroyed" << std::endl;
}
/*
	Something weird, because it's not possible to copy or assign constant attributes of the class
*/
Form& Form::operator = (const Form& orig) {
	if (this == &orig) {
		return *this;
	}
	_status = orig.getStatus();
	std::cout << "Assignment operator. Form " << _name << " assigned" << std::endl;
	return *this;
}
//--------------------------------
Form::Form(std::string name, int sign, int exec) : _name(name), _gradeSign(sign), _gradeExec(exec) {
	if (sign < MAXGRADE || exec < MAXGRADE) {
		throw GradeToHighExeption();
	}
	if (sign > MINGRADE ||exec > MINGRADE) {
		throw GradeToLowExeption();
	}
	_status = false;
	std::cout << "Full constructor. Form " << _name << " created" << std::endl;
}
//---------------- getters ----------------
std::string Form::getName() const {
	return _name;
}
int Form::getGradeSign() const {
	return _gradeSign;
}
int Form::getGradeExec() const {
	return _gradeExec;
}
bool Form::getStatus() const {
	return _status;
}
//---------------- methods ----------------

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_status == true) {
		throw AlreadySignedExeption();
	}
	if (bureaucrat.getGrade() > _gradeSign) {
		throw GradeToLowExeption();
	}
	_status = true;
	std::cout << "Bureaucrat " << bureaucrat.getName() << " successfuly signed form " << _name << "." << std::endl; 
}

//---------------- exceptions ----------------
const char* Form::GradeToHighExeption::what() const throw() {
	return (RED "Grade is too high!" NRM);
}
const char* Form::GradeToLowExeption::what() const throw() {
	return (RED "Grade is too low!" NRM);
}
const char* Form::AlreadySignedExeption::what() const throw() {
	return (YELLOW "Form is already signed!" NRM);
}

//---------------- "<<" overload ----------------
std::ostream& operator << (std::ostream &ss, const Form& form) {
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
