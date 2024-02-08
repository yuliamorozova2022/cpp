#include "MutantStack.h"
#include <iostream>
// #include <cassert>

template < class InputIt>
void printStack(InputIt start, InputIt end) {
	// while (stack.empty() != true) {
	// 	std::cout << *sta << std::endl;
	// }
	std::cout << "Stack from bottom to top:" << std::endl;
	while (start != end) {
		std::cout << *start << std::endl;
		++start; 
	}
}

int main() {
	//test from the task
	std::cout << "	The 1st test (from task)." << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	std::cout << "----" << mstack.top() << std::endl;
	std::cout << "----stack size = " << mstack.size() << std::endl;
	mstack.push(17);
	std::cout << "----" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "----stack size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] 
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	printStack(it, ite);
	std::cout << "-------------------------------------------------------------" << std::endl;	
	{
		//copy constructor test
		std::cout << "	Copy constructor test." << std::endl;
		std::cout << "copy stack s:" << std::endl;
		std::stack<int> s(mstack);
		MutantStack<int>::iterator its = mstack.begin();
		MutantStack<int>::iterator ites = mstack.end();
		printStack(its, ites);
		mstack.pop();
		mstack.pop();
		it = mstack.begin();
		ite = mstack.end();
		std::cout << "copy stack s:" << std::endl;
		printStack(its, ites);
		std::cout << "orig stack:" << std::endl;
		printStack(it, ite);
	}
	{
		std::cout << "	String stack test." << std::endl;
		MutantStack<std::string> stack;
		std::cout << "	stack size = " << stack.size() << std::endl;
		stack.push("hello00");
		stack.push("hello11");
		std::cout << "	stack size = " << stack.size() << std::endl;
		MutantStack<std::string>::iterator start = stack.begin();
		MutantStack<std::string>::iterator end = stack.end();
		printStack(start, end);
		stack.push("hello22");
		std::cout << "top element : " << stack.top() << std::endl;
		end = stack.end();
		printStack(start, end);
	}
	return 0;
}