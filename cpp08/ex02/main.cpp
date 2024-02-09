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
	std::cout << "----top element in the stack: " << mstack.top() << std::endl;
	std::cout << "----stack size = " << mstack.size() << std::endl;
	mstack.push(17);
	std::cout << "----top element in the stack: " << mstack.top() << std::endl;
	std::cout << "----stack size = " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "----top elemet was removed. Stack size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] 
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	printStack(it, ite);
	std::cout << "----top element in the stack: " << mstack.top() << std::endl;
	std::cout << "----stack size = " << mstack.size() << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		//copy constructor test
		std::cout << "	The 2nd test (Copy constructor test)" << std::endl;
		// std::cout << "copy stack s:" << std::endl;
		MutantStack<int> s (mstack);
		std::cout << "orig stack size  = " << mstack.size() << std::endl;
		std::cout << "copy stack s size = " << s.size() << std::endl;
			
		// printStack(its, ites);
		mstack.pop();
		mstack.pop();
		it = mstack.begin();
		ite = mstack.end();
		std::cout << "orig stack size  = " << mstack.size() << std::endl;
		std::cout << "----top element in the mstack: " << mstack.top() << std::endl;
		printStack(it, ite);
		std::cout << "copy stack s size = " << s.size() << std::endl;
		std::cout << "----top element in the s stack: " << s.top() << std::endl;
		MutantStack<int>::iterator its = s.begin();
		MutantStack<int>::iterator ites = s.end();
		// s.print();
		printStack(its, ites);
		
		
	}
	std::cout << "-------------------------------------------------------------" << std::endl;
	{
		//string stack test
		std::cout << "	The 3rd test (with strings)" << std::endl;
		std::cout << "	String stack test." << std::endl;
		MutantStack<std::string> stack;
		std::cout << "stack size = " << stack.size() << std::endl;
		stack.push("hello00");
		stack.push("hello11");
		std::cout << "stack size = " << stack.size() << std::endl;
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