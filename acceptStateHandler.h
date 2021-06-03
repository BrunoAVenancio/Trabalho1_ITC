#ifndef ACCEPT_STATE_HANDLER
#define ACCEPT_STATE_HANDLER

#include "operation.h"

typedef struct inputString
{
    char value[21];
    int currentIndex;
}   inputString;

int isStringAcceptable(node **, int  ,inputString *);
void readAndVerifyAllStrings(node **, int);

#endif