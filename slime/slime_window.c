
//  slime_window.c
//  slime
//  [05/11/2016]

#include "slime_window.h"

typedef struct windowContainer_ {
    renderer *ren;
    window *win;
    unsigned int scale;
}windowContainer;

windowContainer slimeWindow;
// slimeWindow is a singleton
// of type windowContainer

void slimeWindowCreate(int width, int height, int scale) {
    slimeWindow.ren = NULL;
    slimeWindow.win = NULL;
    if (scale <= 0) scale = 1;
    slimeWindow.scale = scale;
    
    slimeWindow.win = SDL_CreateWindow( // create the window
                                       /*  window title  */            "",
                                       /*  initial x pos  */           SDL_WINDOWPOS_UNDEFINED,
                                       /*  initial y pos  */           SDL_WINDOWPOS_UNDEFINED,
                                       /*  width in pixels  */         width * scale,
                                       /*  height in pixels  */        height * scale,
                                       /*  flags  */                   SDL_WINDOW_OPENGL);
    // check the window
    if (slimeWindow.win == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    } else printf("Window created!\n");
    // create the renderer
    slimeWindow.ren = SDL_CreateRenderer(slimeWindow.win, -1,
                                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(slimeWindow.ren, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(slimeWindow.ren, 0, 0, 0, 0);
    SDL_RenderClear(slimeWindow.ren);
}

void slimeWindowSetTitle(char *title) {
    SDL_SetWindowTitle(slimeWindow.win, title);
}

renderer *slimeGetWindowRenderer(void) {
    return slimeWindow.ren;
}

