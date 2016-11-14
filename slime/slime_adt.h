
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

unsigned int ll_count(llnode *head);
void ll_append(llnode **head, void *data);
void ll_prepend(llnode **head, void *data);
void ll_reverse(llnode **head);
void *ll_pop(llnode **head);
void *ll_get(llnode **head, unsigned int number);

typedef struct llpool_ {
    llnode *active;
    llnode *inactive;
    unsigned int amountActive;
    unsigned int amountInactive;
    void *(*get)(void);
}llpool;

#endif /* slime_adt_h */
