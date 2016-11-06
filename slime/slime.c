
//  slime.c
//  slime
//  [04/11/2016]

#include "slime.h"

const unsigned int FPS = 60; // frames per second
const unsigned int DELAY_TIME = 1000.0f / FPS;
Uint32 frameStart, frameTime;

void slimeCreate(unsigned int width, unsigned int height,
                 unsigned int scale, char *title) {
    // init gfx
    slimeGfxInit();
    // set up window
    slimeWindowCreate(width, height, scale);
    slimeWindowSetTitle(title);
    // init views
    slimeViewsInit();
}

void slimeRun(void) {

    // Get time since last frame
    frameStart = SDL_GetTicks();
    
    // Window Events
    // Poll Input
    slimeInputPoll();
    // Run Views
    slimeViewsRun();
    // Draw
    slimeDraw();
    // Wait
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME) SDL_Delay((int)(DELAY_TIME - frameTime));
    
}
