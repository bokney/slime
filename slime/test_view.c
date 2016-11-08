
//  test_view.c
//  slime
//  [07/11/2016]

#include "test_view.h"

tex *pic = NULL;
sprite *itsprite = NULL;

void test_view_init(void) {
    pic = loadTexture("a_pic.png");
    itsprite = spriteCreate(pic);
    spriteAddFrame(itsprite, 0, 0, 640, 480);
    spriteAddFrame(itsprite, 32, 32, 64, 64);
}

int  test_view_loop(void) {
    slimeRender(itsprite, 0, 0, 0);
    static int sx = 40, sy = -40;
    slimeRender(itsprite, 1, sx, sy);
    sx++; sy++;
    if (sx == 500) sx = -50;
    if (sy == 400) sy = -50;
    return 0;
}

void test_view_exit(void) {
    SDL_free(pic);
    pic = NULL;
    //spriteDestroy(itsprite);
    //itsprite = NULL;
}
