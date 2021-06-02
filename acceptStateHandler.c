#include "acceptStateHandler.h"

//ta tudo desorganizado , me desculpe
//por enquanto so um estado final, depois implemento o codigo com mais de um estado final
int isStringAcceptable(node **stateList,int currentState ,inputString *string)
{
    int isPossible = 0;
    //ver os caminhos
    node *aux = stateList[currentState]->next;

    while(aux != NULL && isPossible == 0 && string->currentIndex < strlen(string->value))
    {
        if(aux->transitionValue == string->value[string->currentIndex])
        {
            if(strlen(string->value) == string->currentIndex + 1 && stateList[aux->nextStateName]->isEndState == 1)
            {
                return 1; // Eh possivel a entrada
            }
            string->currentIndex++;
            isPossible = isStringAcceptable(stateList, aux->nextStateName, string);
        }
        aux = aux->next;
    }
    return isPossible;
}

void readAndVerifyAllStrings(node **stateList, int totalStrings)
{   
    inputString *string = (inputString*)malloc(sizeof(inputString));
    for(int i = 0; i < totalStrings; i++)
    {
        int isPossible = 0;
        int currentInitialState = 0;
        fflush(stdin);
        scanf("%s",string->value);
        string->currentIndex = 0;
        //Posso alterar o valor fixo do 0 para outro estado inical, caso for AFN
        while(isPossible == 0 && stateList[currentInitialState]->isInitialState == 1)
        {
            isPossible = isStringAcceptable(stateList,currentInitialState,string);
            currentInitialState++;
        }
        if(isPossible == 1)
        {
            printf("aceita\n");
        } else
        {
            printf("rejeita\n");
        }
    }
    free(string);
}