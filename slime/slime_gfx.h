
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
    int midX, midY;
}frame;

typedef struct sprite_ {
    tex *texture;
    unsigned int frameAmount;
    llnode *frameList;
}sprite;

tex *loadTexture(char *filepath);
sprite *spriteCreate(tex *texture);
void spriteAddFrame(sprite *sprite, int x, int y, int w, int h);

void slimeGfxInit(void);
// slimeGfxInit() is called
// during slimeCreate()

void slimeDraw(void);
// slimeDraw() is called
// each frame in slimeRun()

#endif /* slime_gfx_h */
