#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    node *next; //proximos estado
    int state; //nome
    char value; //valor
};

node *createLinkedList();
int pushNode(node *, int, char);
void free_linkedList(node *);
void printNode(node **);


#endif