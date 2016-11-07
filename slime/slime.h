
//  slime.h
//  slime
//  [04/11/2016]

#ifndef slime_h
#define slime_h

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "slime_adt.h"
#include "slime_window.h"
#include "slime_gfx.h"
#include "slime_input.h"
#include "slime_views.h"

void slimeCreate(unsigned int width, unsigned int height,
                 unsigned int scale, char *title);

void slimeRun(void);

#endif /* slime_h */
