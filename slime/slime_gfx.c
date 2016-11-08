
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
    newFrame->offsetX = w / 2;
    newFrame->offsetY = h / 2;
    ll_append(&sprite->frameList, newFrame);
    sprite->frameAmount++;
}

void spriteDestroy(sprite *sprite) {
    if (sprite != NULL) {
        unsigned int amount = sprite->frameAmount;
        for (int i = 0; i != amount; i++) {
            frame *tmpFrame = ll_pop(&sprite->frameList);
            free(tmpFrame);
        }
        free(sprite);
    } else {
        printf("Error! Tried to deallocate a NULL sprite\n");
        exit(1); }
}

typedef struct drawCommand_ {
    int x, y;
    int xScale, yScale;
    double rotation;
    sprite *sprite;
    unsigned int frame;
    unsigned int alpha;
}drawCommand;

llnode *drawList = NULL;

drawCommand *createDrawCommand(void) {
    drawCommand *newCommand = (drawCommand *)malloc(sizeof(drawCommand));
    if (newCommand == NULL) {
        printf("Error creating new drawCommand!\n");
        exit(1); }
    return newCommand;
}

void slimeRenderEx(sprite *sprite, int frameNo, int x, int y,
                   double xscale, double yscale, double angle, int alpha) {
    drawCommand *newCommand = createDrawCommand();
    newCommand->x = x;
    newCommand->y = y;
    newCommand->xScale = xscale;
    newCommand->yScale = yscale;
    newCommand->rotation = angle;
    newCommand->alpha = alpha;
    newCommand->sprite = sprite;
    newCommand->frame = frameNo;
    ll_prepend(&drawList, newCommand);
}

void slimeRender(sprite *sprite, int frameNo, int x, int y) {
    slimeRenderEx(sprite, frameNo, x, y, 1, 1, 0, 255);
}

void slimeDraw(void) {
    // purge drawPool
    // first reverse it
    ll_reverse(&drawList);
    // then draw & pop
    unsigned int amount = ll_count(drawList);
    for (int i = 0; i != amount; i++) {
        drawCommand *currentCommand = ll_pop(&drawList);
        frame *currentFrame = ll_get(&currentCommand->sprite->frameList, currentCommand->frame);
        rect *src = &currentFrame->src;
        rect dst = {currentCommand->x - currentFrame->offsetX, currentCommand->y - currentFrame->offsetY, src->w, src->h};
        SDL_SetTextureAlphaMod(currentCommand->sprite->texture, currentCommand->alpha);
        SDL_RenderCopy(slimeGetWindowRenderer(), currentCommand->sprite->texture, src, &dst);
        free(currentCommand);
    }
    renderer *ren = slimeGetWindowRenderer();
    SDL_RenderPresent(ren);
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
}

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
