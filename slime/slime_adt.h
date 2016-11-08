
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
    unsigned int activeAmount;
    llnode *inactive;
    unsigned int inactiveAmount;
    unsigned int totalAmount;
}llpool;

llpool *llpool_create(unsigned int size);
void llpool_purge(llpool *pool);
void llpool_append(llpool *pool, void *data);
void llpool_prepend(llpool *pool, void *data);
void *llpool_pop(llpool *pool);

#endif /* slime_adt_h */
