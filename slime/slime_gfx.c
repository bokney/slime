
//  slime_gfx.c
//  slime
//  [05/11/2016]

#include "slime_gfx.h"

tex *loadTexture(char *filepath) {
    tex *texture = IMG_LoadTexture(slimeGetWindowRenderer(), filepath);
    if (texture == NULL) {
        printf("Error loading %s !!\n", filepath);
        exit(1); }
    printf("Texture %s loaded!\n", filepath);
    return texture;
}

sprite *spriteCreate(tex *texture) {
    sprite *newSprite = (sprite *)malloc(sizeof(sprite));
    newSprite->frameAmount = 0;
    newSprite->texture = texture;
    newSprite->frameList = NULL;
    SDL_SetTextureBlendMode(newSprite->texture, SDL_BLENDMODE_BLEND);
    return newSprite;
}

void spriteAddFrame(sprite *sprite, int x, int y, int w, int h) {
    rect *newRect = (rect *)malloc(sizeof(rect));
    newRect->x = x;
    newRect->y = y;
    newRect->w = w;
    newRect->h = h;
    ll_append(&sprite->frameList, newRect);
    sprite->frameAmount++;
}
