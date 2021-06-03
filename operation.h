#ifndef OPERATION_H
#define OPERATION_H
#include "linkedList.h"

typedef struct transition
{
    char currentState;
    char transitionValue;
    char nextState;
}   transition_t;

int readStatesQuantity();
void readSymbols(char *);
void readInitialStates(node **);
void readEndStates(node **);
void readTransitions(node **, char *);
int readStringQuantity();

#endif