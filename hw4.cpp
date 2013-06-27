#include "hw4.h"

Type stringToType(string s){
	if (s.compare("int") == 0) return INT;
	if (s.compare("sec") == 0) return SECOND;
	if (s.compare("min") == 0) return MINUTE;
	if (s.compare("hour") == 0) return HOUR;
	if (s.compare("day") == 0) return DAY;
	if (s.compare("week") == 0) return WEEK;
	if (s.compare("bool") == 0) return BOOL;
	if (s.compare("string") == 0) return STRING;
	if (s.compare("id") == 0) return ID;
}

string typeToString(Type type){
	if (type == INT) return "INT";
	if (type == SECOND) return "SECOND";
	if (type == MINUTE) return "MINUTE";
	if (type == HOUR) return "HOUR";
	if (type == DAY) return "DAY";
	if (type == WEEK) return "WEEK";
	if (type == BOOL) return "BOOL";
	if (type == STRING) return "STRING";
	if (type == ID) return "ID";
}
