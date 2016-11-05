
//  slime_adt.h
//  slime
//  [05/11/2016]

#ifndef slime_adt_h
#define slime_adt_h

#include <stdio.h>
#include <stdlib.h>

typedef struct llnode_ {
    void *data;
    struct llnode_ *next;
}llnode;

#endif /* slime_adt_h */
