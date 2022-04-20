CC=i686-w64-mingw32-gcc
CFLAGS=-g

all: grsoft grsoft.exe

grsoft: grsoft.tab.c lex.yy.c
	gcc $(CFLAGS) -I/usr/include -o $@ grsoft.tab.c -lSDL2 -lm

grsoft.exe: grsoft.tab.c lex.yy.c
	$(CC) $(CFLAGS) -I/usr/include -I/usr/include/x86_64-linux-gnu -DYY_NO_UNISTD_H -o $@ grsoft.tab.c -L/usr/local/cross-tools/lib -lSDL2 -lm

check:
	echo unimp.

clean:
	rm grsoft grsoft.exe
