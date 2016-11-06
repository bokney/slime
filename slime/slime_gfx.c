
//  slime_gfx.c
//  slime
//  [05/11/2016]

#include "slime_gfx.h"

void slimeGfxInit(void) {
    // init SDL Video
    if (SDL_Init(SDL_INIT_VIDEO)) { // error
        printf("Error initialising SDL: %s\n", SDL_GetError());
        exit(1);
    } else printf("SDL successfully initialised.\n");
    // init SDL_Image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
        printf("Error during IMG_Init (SDL_Image): %s\n", SDL_GetError());
        exit(1);
    } else printf("SDL_Image successfully initialised :)\n");
}

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
    int x, y;
    int xScale, yScale;
    double rotation;
    sprite *sprite;
    unsigned int frame;
    int alpha;
}drawCommand;

void slimeDraw(void) {
    // purge draw list
    // first reverse it
}
