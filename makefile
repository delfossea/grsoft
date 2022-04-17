CC=i686-w64-mingw32-gcc
CFLAGS=-g

grsoft.exe: grsoft.tab.c lex.yy.c
	$(CC) $(CFLAGS) -I/usr/local/cross-tools/include -o $@ grsoft.tab.c -L/usr/local/cross-tools/lib -lSDL2 -lm
