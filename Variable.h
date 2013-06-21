#ifndef __VARIABLE_H
#define __VARIABLE_H

#include <string>
#include "hw4.h"

using namespace std;

class Variable {
private:
	string name;
	Type type;
	int offset;

public:
	Variable(string name, Type type, int offset):
		name(name),type(type),offset(offset)
		{}

	~Variable(){}	

	const string getName() const{
		return name;
	}

	const Type getType() const{
		return type;
	}

	const int getOffset() const{
		return offset;
	}
};

#endif