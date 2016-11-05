
//  slime.h
//  slime
//  [04/11/2016]

#ifndef slime_h
#define slime_h

#include <stdio.h>
#include <stdlib.h>

#include "slime_views.h"

void slimeCreate(unsigned int width, unsigned int height,
                 unsigned int scale, char *title);

void slimeAddView(void (*i)(void), void (*l)(void), void (*e)(void));

void slimeRun(void);

#endif /* slime_h */
