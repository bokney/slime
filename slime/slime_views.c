
//  slime_views.c
//  slime
//  [04/11/2016]

#include "slime_views.h"

typedef struct viewStruct_ {
    void (*init)(void);
    int  (*loop)(void);
    void (*exit)(void);
}viewStruct;

typedef struct viewContainer_ {
    llnode *views;
    unsigned int total;
    unsigned int current;
    bool initialised;
}viewContainer;

viewContainer slimeView;
// slimeView is a singleton
// of type viewContainer

void slimeViewsInit(void) {
    slimeView.current = 0;
    slimeView.total = 0;
    slimeView.views = NULL;
    slimeView.initialised = false;
}

void slimeAddView(void (*i)(void), int (*l)(void), void (*e)(void)) {
    // create a new view
    viewStruct *newView = (viewStruct *)malloc(sizeof(viewStruct));
    newView->init = i;
    newView->loop = l;
    newView->exit = e;
    ll_append(&slimeView.views, newView);
    slimeView.total++;
}

void slimeViewsRun(void) {
    if (slimeView.views != NULL) {
        if (slimeView.current <= slimeView.total) {
            viewStruct *currentView = ll_get(&slimeView.views, slimeView.current);
            if (!slimeView.initialised) {
                currentView->init();
                slimeView.initialised = true;
            }
            int destination = currentView->loop();
            if (destination > 0) {
                currentView->exit();
                slimeView.current = destination;
                currentView = ll_get(&slimeView.views, slimeView.current - 1);
                currentView->init();
            }
        } else {
            printf("Error! Tried to move to view out of bounds!\n");
            exit(1); }
    } else {
        printf("Error! No views to run!\n");
        exit(1); }
}
