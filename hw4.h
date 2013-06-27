#ifndef __HW4_H
#define __HW4_H

#include <string>
#include <list>
using namespace std;

enum Type {
	INT,SECOND=1,MINUTE=60,HOUR=3600,DAY=86400,WEEK=604800,BOOL,STRING,ID
  };

class CaseCond {
public:
	string val;
	Type type;
	int quad;
	CaseCond(string v, Type t, int q): val(v), type(t), quad(q){};
};

Type stringToType(string s);

string typeToString(Type type);

typedef struct 
{
	string text;
	Type type;
	list<int> trueList;
	list<int> falseList;
	list<int> nextList;
	list<int> breakList;
	int quad;
} STYPE;

#define YYSTYPE STYPE

#endif