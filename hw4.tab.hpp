/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INPUT = 258,
     BREAK = 259,
     CASE = 260,
     SWITCH = 261,
     PRINT = 262,
     IF = 263,
     WHILE = 264,
     ERROR = 265,
     IDEN = 266,
     STR = 267,
     NUM = 268,
     SEC = 269,
     MIN = 270,
     HR = 271,
     D = 272,
     W = 273,
     BOOLEAN_VALUE = 274,
     BOOLEAN = 275,
     INTEGER = 276,
     OR = 277,
     AND = 278,
     NEQ = 279,
     EQUALS = 280,
     LE = 281,
     GE = 282,
     NOT = 283,
     ELSE = 284
   };
#endif
/* Tokens.  */
#define INPUT 258
#define BREAK 259
#define CASE 260
#define SWITCH 261
#define PRINT 262
#define IF 263
#define WHILE 264
#define ERROR 265
#define IDEN 266
#define STR 267
#define NUM 268
#define SEC 269
#define MIN 270
#define HR 271
#define D 272
#define W 273
#define BOOLEAN_VALUE 274
#define BOOLEAN 275
#define INTEGER 276
#define OR 277
#define AND 278
#define NEQ 279
#define EQUALS 280
#define LE 281
#define GE 282
#define NOT 283
#define ELSE 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

