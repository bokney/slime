
//  slime_input.h
//  slime
//  [05/11/2016]

#ifndef slime_input_h
#define slime_input_h

#include <stdbool.h>
#include <SDL2/SDL.h>

#include "slime_adt.h"

void slimeInputPoll(void);
// slimeInputPoll() is called
// each frame in slimeRun()

int slimeMouseX(void);
int slimeMouseY(void);

typedef enum mouseButton_ {
    MB_LEFT,
    MB_MIDDLE,
    MB_RIGHT
}mouseButton;

bool slimeCheckMouseButton(mouseButton button);
bool slimeCheckMouseButtonPressed(mouseButton button);
bool slimeCheckMouseButtonReleased(mouseButton button);

#endif /* slime_input_h */
