#ifndef __IDENTIFIER__
#define __IDENTIFIER__

#include <iostream>
#include <exception>
#include <cstdlib>

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif