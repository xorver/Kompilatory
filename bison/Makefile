
all: lichon.tab.c lex.yy.c
	gcc -o parser.exe lichon.tab.c lex.yy.c

lichon.tab.c: lichon.y
	bison -d lichon.y

lex.yy.c: lichon.l
	flex lichon.l

test: all
	parser.exe < test.txt > output.txt