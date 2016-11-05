
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
    frame *newFrame = (frame *)malloc(sizeof(frame));
    newFrame->src.x = x;
    newFrame->src.y = y;
    newFrame->src.w = w;
    newFrame->src.h = h;
    newFrame->midX = x + (w / 2);
    newFrame->midY = y + (h / 2);
    ll_append(&sprite->frameList, newFrame);
    sprite->frameAmount++;
}

typedef struct drawCommand_ {
    int x, y, xScale, yScale;
    
}drawCommand;
