
//  slime_views.c
//  slime
//  [04/11/2016]

#include "slime_views.h"

typedef struct viewStruct_ {
    void (*init)(void);
    void (*loop)(void);
    void (*exit)(void);
}viewStruct;

typedef struct viewContainer_ {
    llnode *views;
    unsigned int total;
    unsigned int current;
}viewContainer;

viewContainer slimeView;

void slimeViewsInit(void) {
    slimeView.current = 0;
    slimeView.total = 0;
    slimeView.views = NULL;
}

void slimeAddView(void (*i)(void), void (*l)(void), void (*e)(void)) {

}

void slimeViewsRun(void) {
    
}
