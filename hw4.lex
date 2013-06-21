%{
	#include "hw4.h"
	#include "hw4.tab.hpp"
	#include "stdio.h"
%}

%option yylineno
%option noyywrap

ops		([-(){}:;=+\*/<>])  

%%


"and"		return AND;
"or"		return OR;
"sec"		{ return SEC; }
"min" 		{ return MIN; }
"hr" 		{ return HR; }
"day" 		{ return D; }
"week" 		{ return W; }
"int" 		return INTEGER;
"print" 	return PRINT;
"input" 	return INPUT;
"true"		{ yylval.text = "1"; return BOOLEAN_VALUE; }
"false"		{ yylval.text = "0"; return BOOLEAN_VALUE; }
"if"		return IF;
"else" 		return ELSE;
"while" 	return WHILE;
"break" 	return BREAK;
"not" 		return NOT;
"bool"		return BOOLEAN;
"switch"	return SWITCH;
"case" 		return CASE;
{ops}		return *yytext;
"=="		return EQUALS;
"!="		return NEQ;
"<="		return LE;
">="		return GE;
(\"[^"]*\") 		{ yylval.text = strdup(yytext); return STR; }
[a-zA-Z]+			{ yylval.text = strdup(yytext); return IDEN; } 
([1-9][0-9]*|0)		{ yylval.text = strdup(yytext); return NUM; }
[ \t\n\r]			; //whitespace	
("//"[^\n]*\n)		; //comment
.				return ERROR;
%%