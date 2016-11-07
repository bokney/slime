
//  slime_adt.c
//  slime
//  [05/11/2016]

#include "slime_adt.h"

llnode *createNode(void) {
    llnode *newNode = (llnode *)malloc(sizeof(llnode));
    newNode->data = NULL;
    newNode->next = NULL;
    return newNode;
}

unsigned int ll_count(llnode *head) {
    unsigned int count = 0;
    while (head != NULL) {
        head = head->next;
        count++; }
    return count;
}

void ll_append(llnode **head, void *data) {
    // malloc a new node
    llnode *newNode = createNode();
    // assign it's data
    newNode->data = data;
    // stick it at the end of head
    if (*head != NULL) {
        llnode *tmpNode = *head;
        while (tmpNode->next != NULL) tmpNode = tmpNode->next;
        tmpNode->next = newNode;
    } else *head = newNode;
}

void ll_prepend(llnode **head, void *data) {
    // malloc a new node
    llnode *newNode = createNode();
    // assign it's data
    newNode->data = data;
    // stick it at the beginning of head
    newNode->next = *head;
    *head = newNode;
}

void ll_reverse(llnode **head) {
    llnode *prev = NULL;
    llnode *current = *head;
    llnode *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void *ll_pop(llnode **head) {
    // removes first item from list
    // returns its data
    if (*head != NULL) {
        llnode *tmpNode = *head;
        void *data = tmpNode->data;
        *head = tmpNode->next;
        free(tmpNode);
        return data;
    } else {
        printf("Careful now, trying to pop when there ain't no nodes\n");
        return NULL;
    }
}

void *ll_get(llnode **head, unsigned int number) {
    llnode *tmpNode = *head;
    if (tmpNode != NULL) {
        for (int i = 0; i != number; i++) {
            tmpNode = tmpNode->next;
            if (tmpNode == NULL) {
                printf("Error! Reached for a Linked List node out of bounds!\n");
                exit(1); }
        }
    } else {
        printf("Error! no nodes to retrieve!\n");
        exit(1);
    }
    return tmpNode->data;
}

void ll_purge(llnode **head) {
    llnode *curr = *head;
    llnode *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}
