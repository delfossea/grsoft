#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<SDL2/SDL.h>
SDL_Window* pWindow = NULL;
SDL_Renderer* renderer = NULL;
SDL_bool done=SDL_TRUE;
SDL_Event event;
int b1,b2;
static jmp_buf buf;
void hplot(SDL_Renderer*s,int x, int y) {
SDL_RenderDrawPoint(s,x,y);b1=x;b2=y;
}
void main(int argc, char * argv[]) {
char s[1024];
float I;
float HCOLOR;
srand48(1234);
L10: printf("%c[2J",27);
L20: for(I=1;I<=10;I++) {
L30: printf("%g\n",drand48()*1);
L40: };
while(!done) {
while (SDL_PollEvent(&event)) {
if (event.type == SDL_QUIT) {
done=SDL_TRUE;
}
}
}
SDL_Quit();
}
