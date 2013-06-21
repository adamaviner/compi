#ifndef __HW4_H
#define __HW4_H

#include "string.h"

enum Type {
	INT,SECOND=1,MINUTE=60,HOUR=3600,DAY=86400,WEEK=604800,BOOL,STRING,ID
  };

Type stringToType(const char* string);

const char* typeToString(Type type);

typedef struct 
{
	char* text;
	Type type;
} STYPE;

#define YYSTYPE STYPE

#endif