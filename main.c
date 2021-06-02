#include "acceptStateHandler.h"

int main()
{
    // linha1
    int totalStates = readStatesQuantity();
    node *stateList[totalStates];
    for(int i = 0; i < totalStates; i++)
    {
        stateList[i] = createLinkedList();
    }
  
    //linha2
    char *sigma = (char*)calloc(10,sizeof(char));
    readSymbols(sigma);
  
    //linha 3
    readInitialStates(stateList);

    //linha 4
    readEndStates(stateList);
    
    //linha 5 e 6
    readTransitions(stateList);
    
    
    //Linha 7 e 8
    int totalStringsToRead = readStringQuantity();

    //Operacao para descobrir se pertence ou nao à linguagem pelo automato
    readAndVerifyAllStrings(stateList,totalStringsToRead);
    
    //Liberar
    for(int i = 0; i < totalStates; i++)
    {
        freeLinkedList(stateList[i]);
    }
}