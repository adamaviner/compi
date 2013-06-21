#ifndef __SCOPE_H
#define __SCOPES_H

#include <list>
#include <string>
#include "Variable.h"
#include "hw4.h"
#include "output.hpp"

using namespace std;

class Scope {
private:
	list<Variable> variables;
	int offset;

public:
	Scope(int offset):
		offset(offset)
	{}

	~Scope(){}	

	bool add(string name, Type type){

		if (isDefined(name)) return false;
		Variable variable(name,type,offset++);
		variables.push_back(variable);
		return true;
	}

	const Variable* getVariable(string name) const {
		list<Variable>::const_iterator iterator;
		for (iterator = variables.begin(); iterator != variables.end(); ++iterator) 
    		if (iterator->getName().compare(name) == 0) return &*iterator;
    	return NULL;
	}

	bool isDefined(string name){
		return getVariable(name) != NULL;
	}

	int getOffset (){
		return offset;
	}

	void printScope(){
		list<Variable>::const_iterator iterator;
		for (iterator = variables.begin(); iterator != variables.end(); ++iterator) 
    		output::printVar(iterator->getName().c_str(),iterator->getOffset(), typeToString(iterator->getType()));
	}
};

#endif