#ifndef __SERIALIZER__
#define __SERIALIZER__

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer {
public:
//---------------- methods ------------------
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
//-------- Orthodox Canonical Form ---------
	Serializer();
	Serializer(const Serializer& orig);
	~Serializer();
	Serializer& operator = (const Serializer& orig);
};

#endif