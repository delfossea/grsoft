CFLAGS=-g -O2

all: soft #grsoft.exe

calendar2ics: calendar.l calendar2ics.y
	flex calendar.l
	bison calendar2ics.y
	gcc $(CFLAGS) -Wno-implicit-function-declaration -o $@ calendar2ics.tab.c

yy.lex.c: grsoft.l
	flex $+

grsoft.tab.c: grsoft.y
	bison $+ 

soft: soft.l soft.y 
	flex soft.l
	bison soft.y
	gcc $(CFLAGS) -o $@ soft.tab.c -lm 

grsoft: grsoft.tab.c yy.lex.c
	gcc $(CFLAGS) -o $@ grsoft.tab.c -lm -lSDL2

grsoft.exe: grsoft.tab.c lex.yy.c
	x86_64-w64-mingw32-gcc $(CFLAGS) -I/usr/local/cross-tools/include -o $@ grsoft.tab.c -L/usr/local/cross-tools/lib -lSDL2 -lm

soft.exe: soft.l soft.y
	flex soft.l
	bison soft.y
	x86_64-w64-mingw32-gcc -g -o $@ soft.tab.c -lm

clean:
	rm soft calc lex.yy.c soft.tab.c grsoft.tab.c calendar2ics.tab.c calendar2ics

install: grsoft soft
	sudo install -b grsoft /usr/local/bin
	sudo install -b soft /usr/local/bin

dist: grsoft grsoft.tab.c lex.yy.c
	cp $+ ../grsoft

test: soft
	python run_tests.py
