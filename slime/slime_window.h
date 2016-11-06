
//  slime_window.h
//  slime
//  [05/11/2016]

#ifndef slime_window_h
#define slime_window_h

#include <SDL2/SDL.h>

typedef SDL_Window window;
typedef SDL_Renderer renderer;

void slimeWindowCreate(int width, int height, int scale);
void slimeWindowSetTitle(char *title);

renderer *slimeGetWindowRenderer(void);

#endif /* slime_window_h */
