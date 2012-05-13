#include "SS.c"

int SS_WIDTH      = 800;
int SS_HEIGHT     = 600;
int SS_FULLSCREEN = 1;

void DrawScreen(int t) {
    int x, y;
    Color c;
    SS_STARTDRAW;


    for(y = 0; y < SS_HEIGHT; y++ ) 
        for( x = 0; x < SS_WIDTH; x++ ) 
            SS_Putpixel(x, y, SS_Color((x + t) % 255, (y + t) % 255, t % 255));

    SS_ENDDRAW;
}

int main(){
    int t;

    SS_Init();
    while(SS_CheckKey()) 
         DrawScreen(t++);

    SS_Quit();
    return 0;
}
