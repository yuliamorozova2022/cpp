#ifndef __AFORM__
#define __AFORM__

#include <iostream>
#include <exception>
#include "Bureaucrat.h"

// #define RED "\033[0;91m"
// #define GREEN "\033[0;32m"
// #define YELLOW "\033[0;33m"
// #define NRM "\033[0;39m"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */
class Bureaucrat;

class AForm {
public:
//-------- Orthodox Canonical Form ---------
	AForm();
	AForm(const AForm& orig);
	virtual ~AForm();
	AForm& operator = (const AForm& orig);
//------------------------------------------
	AForm(std::string name, int sign, int exec);
//---------------- getters -----------------
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getStatus() const;
//---------------- methods ------------------
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0; // makes class AForm abstract
//---------------- exceptions ---------------
	class GradeToHighExeption : public std::exception {
		const char* what() const throw();
	};
	class GradeToLowExeption : public std::exception {
		const char* what() const throw();
	};
	class AlreadySignedExeption : public std::exception {
		const char* what() const throw();
	};
	class NotSignedExeption : public std::exception {
		const char* what() const throw();
	};
	// class SomethingWrongExeption : public std::exception {
	// 	const char* what() const throw();
	// };
//---------------- attributes ----------------
private:
	const std::string _name;
	const int _gradeSign;
	const int _gradeExec;
	bool _status;
};

std::ostream& operator << (std::ostream &ss, const AForm& form);

#endif