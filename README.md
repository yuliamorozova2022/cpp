This 42 project is a collection of modules written in C++.



General rules 

• Compilation with c++ and the flags-Wall-Wextra-Werror 

• Code should still compile with the flag-std=c++98 

Formatting and naming conventions 

• Class names in UpperCamelCase format. Files containing class code will always be named according to the class name. 

Forbidden

• Any function implementation put in a header file (except for function templates).

• Any other external library. It means C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: *printf(), *alloc() and free(). 

• Unless explicitly stated otherwise, the using namespace <ns_name> and friend keywords are forbidden. 

• The STL is allowed only in Modules 08 and 09. That means: no Containers (vector/list/map, and so forth) and no Algorithms (anything that requires including the <algorithm> header) until then. 

• From Module 02 to Module 09, classes must be designed in the Orthodox Canonical Form, except when explicitly stated otherwise. 