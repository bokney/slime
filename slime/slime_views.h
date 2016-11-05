
//  slime_views.h
//  slime
//  [04/11/2016]

#ifndef slime_views_h
#define slime_views_h

#include <SDL2/SDL.h>

#include "slime_adt.h"

void slimeAddView(void (*i)(void), void (*l)(void), void (*e)(void));
void slimeViewsRun(void);

#endif /* slime_views_h */
