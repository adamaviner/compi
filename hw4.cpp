#include "hw4.h"

Type stringToType(const char* string){
	if (strcmp(string,"int") == 0) return INT;
	if (strcmp(string,"sec") == 0) return SECOND;
	if (strcmp(string,"min") == 0) return MINUTE;
	if (strcmp(string,"hour") == 0) return HOUR;
	if (strcmp(string,"day") == 0) return DAY;
	if (strcmp(string,"week") == 0) return WEEK;
	if (strcmp(string,"bool") == 0) return BOOL;
	if (strcmp(string,"string") == 0) return STRING;
	if (strcmp(string,"id") == 0) return ID;
}

const char* typeToString(Type type){
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
