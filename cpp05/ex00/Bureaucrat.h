#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <exception>

#define MAXGRADE 1
#define MINGRADE 150

#define RED "\033[0;91m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define NRM "\033[0;39m"

/* 
The Orthodox Canonical Class Form
	A default constructor: used internally to initialize objects and data members when no other value is available.
	A copy constructor: used in the implementation of call-by-value parameters.
	An assignment operator: used to assign one value to another.
	A destructor: Invoked when an object is deleted.
 */

class Bureaucrat {
public:
//-------- Orthodox Canonical Form ---------
	Bureaucrat();
	Bureaucrat(const Bureaucrat& orig);
	/*virtual*/ ~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat& orig);
//------------------------------------------
	Bureaucrat(std::string name, int grade);
//---------------- getters -----------------
	std::string getName() const;
	int getGrade() const;
//---------------- methods ------------------
	void increaseGrade(int size);
	void decreaseGrade(int size);
//---------------- exceptions ---------------
	class GradeToHighExeption : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeToLowExeption : public std::exception {
		virtual const char* what() const throw();
	};

	class SomethingWrongExeption : public std::exception {
		virtual const char* what() const throw();
	};
//---------------- attributes ----------------
protected:
	const std::string _name;
	int _grade;
};

std::ostream& operator << (std::ostream &ss, const Bureaucrat& bureaucrat);

#endif