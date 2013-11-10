
all: scaner.exe

scaner.exe: lex.yy.c
	gcc lex.yy.c -L"C:\Program Files (x86)\GnuWin32\lib" -lfl -o scaner.exe

lex.yy.c: lab2.l
	flex lab2.l
	
test: all
	scaner.exe < test.txt > output.txt