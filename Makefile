all: hw4.exe

hw4.exe: hw4.tab.cpp lex.yy.c
	g++ -Wno-write-strings hw4.tab.cpp lex.yy.c output.cpp hw4.cpp bp.cpp -o ex4.exe

hw4.tab.cpp: hw4.ypp
	bison --defines hw4.ypp

lex.yy.c: hw4.lex
	lex hw4.lex