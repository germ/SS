/*  _____    ______     Super Simple: The simplest way to draw shit in C
 * /\  ___\ /\  ___\    Because plotting pixels should be easy.
 * \ \___  \\ \___  \   
 *  \/\_____\\/\_____\  Based off http://friedspace.com/SDLTest.c use it if you need
 *   \/_____/ \/_____/  your drawing code to span multiple files. This is just for
 *                      simple experimentation and fiddling around. For any
 *      Keep Calm       decent size project do not use this.
 *       Hack On        
 *        Germ          This code is just a little hack to make experimentation
 *                      quick and easy.
 */

#include <SDL/SDL.h>

typedef Uint32 Color;

extern int SS_WIDTH;
extern int SS_HEIGHT;
extern int SS_FULLSCREEN;

/* A bunch of predefined colors for your use */
#define SC_White 	0xFFFFFF
#define SC_Silver 	0xC0C0C0
#define SC_Gray 	0x808080
#define SC_Black 	0x000000
#define SC_Red 	    0xFF0000
#define SC_Maroon 	0x800000
#define SC_Yellow 	0xFFFF00
#define SC_Olive 	0x808000
#define SC_Lime 	0x00FF00
#define SC_Green 	0x008000
#define SC_Aqua 	0x00FFFF
#define SC_Teal 	0x008080
#define SC_Blue 	0x0000FF
#define SC_Navy 	0x000080
#define SC_Fuchsia  0xFF00FF
#define SC_Purple 	0x800080

/* Macros to hide surface locking and unlocking */
#define SS_STARTDRAW if(SDL_MUSTLOCK(SS_SCREEN)) if(SDL_LockSurface(SS_SCREEN) < 0) return
#define SS_ENDDRAW   if(SDL_MUSTLOCK(SS_SCREEN)) SDL_UnlockSurface(SS_SCREEN); SDL_Flip(SS_SCREEN)

/* Yes it's a global variable, Get over it. 
 * It's just the surface that everything will be drawn to */
SDL_Surface*    SS_SCREEN;

/* Sets up the basic enviroment for drawing */
void SS_Init() {
    if (SS_FULLSCREEN) SS_SCREEN = SDL_SetVideoMode(SS_WIDTH, SS_HEIGHT, 32, SDL_NOFRAME    | SDL_HWSURFACE);
    else               SS_SCREEN = SDL_SetVideoMode(SS_WIDTH, SS_HEIGHT, 32, SDL_FULLSCREEN | SDL_HWSURFACE);
    
    if (SS_SCREEN == NULL) {
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) 
        exit(EXIT_FAILURE);
}

/* Create a color, range 0-255 */
Color SS_Color(int r, int g, int b) {
    return (Uint32)((Uint32)r << 16) | ((Uint32)g << 8) | ((Uint32)b);
}

/* Places a pixel, color is specified in hex */
void SS_Putpixel(int x, int y, Color color) {
    Uint32 *pixmem32;
  
    pixmem32 = (Uint32*) SS_SCREEN->pixels + (y * SS_WIDTH) + x;
    *pixmem32 = color;
}

/* Returns 0 if a key has been pressed */
int  SS_CheckKey() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {      
         switch (event.type) {
             case SDL_QUIT:
                return 0;
             case SDL_KEYDOWN:
                return 0;
         }
    }
    return 1;
}

/* Calls SDL cleanup */
void SS_Quit() {
    SDL_Quit();
}
