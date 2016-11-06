
//  slime_views.h
//  slime
//  [04/11/2016]

#ifndef slime_views_h
#define slime_views_h

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "slime_adt.h"

void slimeAddView(void (*i)(void), void (*l)(void), void (*e)(void));

void slimeViewsInit(void);
// slimeViewsInit() is called
// during slimeCreate()
void slimeViewsRun(void);
// slimeViewsRun() is called
// each frame in slimeRun()

#endif /* slime_views_h */
