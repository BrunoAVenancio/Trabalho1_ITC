#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;
struct node
{
    int isEndState;
    int isInitialState;
    node *next; //proximos estado
    int nextStateName; //nome do proximo estado, se for q2 = 2
    char transitionValue; //valor da transicao
};

node *createLinkedList();
int pushNode(node *, int, char);
void freeLinkedList(node *);

#endif