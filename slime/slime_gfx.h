
//  slime_gfx.h
//  slime
//  [05/11/2016]

#ifndef slime_gfx_h
#define slime_gfx_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "slime_adt.h"
#include "slime_window.h"

typedef SDL_Rect rect;
typedef SDL_Texture tex;

typedef struct frame_ {
    rect src;
    int offsetX, offsetY;
}frame;

typedef struct sprite_ {
    tex *texture;
    unsigned int frameAmount;
    llnode *frameList;
}sprite;

tex *loadTexture(char *filepath);
void freeTexture(tex *texture);

sprite *spriteCreate(tex *texture);
void spriteAddFrame(sprite *sprite, int x, int y, int w, int h);
void spriteDestroy(sprite *sprite);

void slimeRender(sprite *sprite, int frameNo, int x, int y);
void slimeRenderEx(sprite *sprite, int frameNo, int x, int y,
                   double xscale, double yscale, double angle, int alpha);

void slimeGfxInit(void);
// slimeGfxInit() is called
// during slimeCreate()

void slimeGfxExit(void);
// slimeGfxExit() is called
// during slimeExit()

void slimeDraw(void);
// slimeDraw() is called
// each frame in slimeRun()

#endif /* slime_gfx_h */
