
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
    static int sx = 40, sy = -40, ss = 0;
    slimeRender(itsprite, 1, sx, sy);
    sx++; sy += 2; ss++;
    if (sx == 360) sx = -50;
    if (sy == 280) sy = -50;
    if (ss == 100) {
        ss = 0;
        return 1;
    }
    return 0;
}

void test_view_exit(void) {
    freeTexture(pic);
    spriteDestroy(itsprite);
}
