
//  slime_component.c
//  slime
//  [12/11/2016]

#include "slime_component.h"

typedef struct slimeComponent_ {
    void (*init)(void);
    void (*loop)(void);
    void (*exit)(void);
    bool initialised;
}slimeComponent;

llnode *componentList = NULL;

void slimeCreateComponents(void);
void slimeComponentAdd(slimeComponent *component);
slimeComponent *slimeComponentCreate(void (*init)(void), void (*loop)(void), void (*exit)(void));
