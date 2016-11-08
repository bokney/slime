
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
    unsigned int next;
    bool moving;
    bool initialised;
}viewContainer;

viewContainer slimeView;
// slimeView is a singleton
// of type viewContainer

void slimeViewsInit(void) {
    slimeView.views = NULL;
    slimeView.total = 0;
    slimeView.current = 0;
    slimeView.next = 0;
    slimeView.moving = false;
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

        if (slimeView.current < slimeView.total) {
            viewStruct *currentView = ll_get(&slimeView.views, slimeView.current);
            if (!slimeView.initialised) {
                currentView->init();
                slimeView.initialised = true;
            } else if (slimeView.moving) {
                currentView->exit();
                slimeView.current = slimeView.next;
                currentView = ll_get(&slimeView.views, slimeView.current);
                currentView->init();
                slimeView.moving = false;
            }
            int destination = currentView->loop();
            if (destination > 0) {
                destination--;
                if (destination < slimeView.total) {
                    slimeView.moving = true;
                    slimeView.next = destination;
                } else {
                    printf("Error! Tried to move to nonexistant view!\n");
                    exit(1); }
            }
        } else {
            printf("Error! Current view (%i) out of bounds!\n", slimeView.current);
            exit(1); }
        
    } else {
        printf("Error! No views to run!\n");
        exit(1); }
    
    /*
    
    if (slimeView.views != NULL) {
        if (slimeView.current <= slimeView.total) {
            viewStruct *currentView = ll_get(&slimeView.views, slimeView.current);
            if (!slimeView.initialised) {
                currentView->init();
                slimeView.initialised = true;
            }
            int destination = currentView->loop();
            if (destination > 0) {
                if (destination <= slimeView.total) {
                    currentView->exit();
                    slimeView.current = destination - 1;
                    printf("moving tp %i\n", slimeView.current);
                    currentView = ll_get(&slimeView.views, slimeView.current);
                    currentView->init();
                } else {
                    printf("Error! Tried to move to view out of bounds!\n");
                    exit(1); }
            }
        } else {
            printf("Error! Tried to move to view out of bounds!\n");
            exit(1); }
    } else {
        printf("Error! No views to run!\n");
        exit(1); }
     */
}
