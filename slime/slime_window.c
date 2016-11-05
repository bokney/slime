
//  slime_window.c
//  slime
//  [05/11/2016]

#include "slime_window.h"

typedef struct windowContainer_ {
    renderer *ren;
    window *win;
    unsigned int scale;
}windowContainer;

windowContainer slimeWindow;

renderer *slimeGetWindowRenderer(void) {
    return slimeWindow.ren;
}

