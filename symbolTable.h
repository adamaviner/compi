#ifndef __SYMBOLTABLE_H
#define __SYMBOLTABLE_H

#include <list>
#include <string>
#include "Scope.h"
#include "Variable.h"
#include "hw4.h"
#include "output.hpp"

using namespace std;

class SymbolTable {
private:
	list<Scope> scopes;

public:
	SymbolTable(){
	}

	~SymbolTable(){}	

	bool startScope(){
		int offset=0;
		if(!scopes.empty()) offset = scopes.back().getOffset();
		Scope scope(offset);
		scopes.push_back(scope);
	}

	bool endScope(){
		output::endScope();
		scopes.back().printScope();
		scopes.pop_back();
	}

	bool addVariable(string name, Type type){
		if (isDefined(name)) return false;
		return scopes.back().add(name, type);
	}

	const Variable* getVariable(string name) const{
		list<Scope>::const_iterator iterator;
		const Variable* var = NULL;
		for (iterator = scopes.begin(); iterator != scopes.end(); ++iterator){
			const Variable* var2 = iterator->getVariable(name);
			if (var2 != NULL) var = var2;
		}
    	return var;
	}

	Type getType (string name){
		return (getVariable(name)->getType());
	}

	int getOffset(string name){
		Variable* var = getVariable(name);
		if (var == NULL) return -1;
		return var.getOffset();
	}
		

	bool isDefined(string name){
		return getVariable(name) != NULL ;
	}

	void printScope(){
		scopes.back().printScope();
	}
};

#endif