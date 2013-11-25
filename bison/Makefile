
all: lichon.tab.c lex.yy.c
	gcc -o parser lichon.tab.c lex.yy.c -std=gnu99

lichon.tab.c: lichon.y
	bison -d lichon.y

lex.yy.c: lichon.l
	flex lichon.l

test: all
	./parser < test.txt > output.txt