CFLAGS=-g

all: grsoft

yy.lex.c: grsoft.l
	flex $+

grsoft.tab.c: grsoft.y
	bison $+ 

soft.tab.c: soft.y
	bison $+ 

soft: soft.tab.c yy.lex.c
	gcc $(CFLAGS) -o $@ soft.tab.c -lm 

grsoft: grsoft.tab.c yy.lex.c
	gcc $(CFLAGS) -o $@ grsoft.tab.c -lm -lSDL2

grsoft.exe: grsoft.tab.c lex.yy.c
	i686-w64-mingw32-gcc $(CFLAGS) -I/usr/local/cross-tools/include -o $@ grsoft.tab.c -L/usr/local/cross-tools/lib -lSDL2 -lm

soft.exe: soft.tab.c yy.lex.c
	i686-w64-mingw32-gcc $(CFLAGS) -I/usr/local/cross-tools/include -o $@ soft.tab.c -L/usr/local/cross-tools/lib 

clean:
	rm calc lex.yy.c soft.tab.c grsoft.tab.c

check: grsoft
	echo unimp.
	
install: grsoft soft
	sudo install -b grsoft /usr/local/bin
	sudo install -b soft /usr/local/bin

dist: grsoft grsoft.tab.c lex.yy.c
	cp $+ ../grsoft
