
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(1){
	std::cout << "Default Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& orig) : _name(orig.getName()) {
	_grade = orig.getGrade();
	std::cout << "Copy constructor. Bureaucrat " << _name << " copied" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name <<" destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& orig) {
	if (this == &orig) {
		return *this;
	}
	_grade = orig.getGrade();
	std::cout << "Assignment operator. Bureaucrat " << orig.getName() << " assigned" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1) {
		throw SomethingWrongExeption();
	}
	if (grade > MINGRADE) {
		throw GradeToLowExeption();
	}
	if (grade < MAXGRADE) {
		throw GradeToHighExeption();
	}
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " with grade " << _grade << " created" << std::endl;
}

//---------------- getters ----------------
std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}
//---------------- methods ----------------
void Bureaucrat::increaseGrade(int size) {
	if (size <= 0) {
		throw SomethingWrongExeption();
	}
	if (_grade - size < MAXGRADE) {
		throw GradeToHighExeption();
	} else {
		_grade -= size;
		std::cout << _name << " new grade after increase is " << _grade << std::endl;
	}
}
void Bureaucrat::decreaseGrade(int size) {
	if (size <= 0) {
		throw SomethingWrongExeption();
	}
	if (_grade + size > MINGRADE) {
		throw GradeToLowExeption();
	} else {
		_grade += size;
		std::cout << _name << " new grade after decrease is " << _grade << std::endl;
	}
}
//---------------- exceptions ----------------
const char* Bureaucrat::GradeToHighExeption::what() const throw() {
	return (RED "Bureaucrat grade is too high" NRM);
}
const char* Bureaucrat::GradeToLowExeption::what() const throw() {
	return (RED "Bureaucrat grade is too low" NRM);
}
//---optional SomethingWrongExeption
const char* Bureaucrat::SomethingWrongExeption::what() const throw() {
	return (YELLOW "Parameter can't be negative or zero" NRM);
}
//---------------- << overload ----------------
std::ostream& operator << (std::ostream &ss, const Bureaucrat& bureaucrat) {
	ss << "Bureaucrat " << bureaucrat.getName() << " had grade " << bureaucrat.getGrade() << ".";
	return ss;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}