#include "acceptStateHandler.h"

int isStringAcceptable(node **stateList,int currentState ,inputString *string)
{
    int isPossible = 0;
    node *aux = stateList[currentState]->next;

    while (aux != NULL && isPossible == 0 && string->currentIndex < strlen(string->value))
    {

        if (aux->transitionValue == string->value[string->currentIndex])
        {
            if (strlen(string->value) == string->currentIndex + 1 && stateList[aux->nextStateName]->isEndState == 1)
            {
                return 1;
            }
            string->currentIndex++;
            isPossible = isStringAcceptable(stateList, aux->nextStateName, string);

            if (isPossible == 0)
            {
                string->currentIndex--;
            }
        }
        aux = aux->next;
    }

    return isPossible;
}

void readAndVerifyAllStrings(node **stateList, int totalStrings)
{
    inputString *string = (inputString*) malloc(sizeof(inputString));

	int i = 0;
    for (i = 0; i < totalStrings; i++)
    {
        int isPossible = 0;
        int currentInitialState = 0;
        setbuf(stdin, NULL);

        scanf("%s", string->value);
        string->currentIndex = 0;

        while (isPossible == 0 && stateList[currentInitialState]->isInitialState == 1)
        {
            isPossible = isStringAcceptable(stateList,currentInitialState,string);
            currentInitialState++;
        }

        if (isPossible == 1)
        {
            printf("aceita\n");
        }
        else
        {
            printf("rejeita\n");
        }
    }
    free(string);
}
