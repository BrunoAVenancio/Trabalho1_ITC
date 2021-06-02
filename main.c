#include "acceptStateHandler.h"

int main()
{
    //Linha 1 - Numero de estados
    int totalStates = readStatesQuantity();
    node *stateList[totalStates];
    for(int i = 0; i < totalStates; i++)
    {
        stateList[i] = createLinkedList();
    }
    //Linha 2 - Os simbolos do conjunto sigma
    char *sigma = (char*)calloc(10,sizeof(char));
    readSymbols(sigma);
    //Linha 3 - Os estados iniciais
    readInitialStates(stateList);
    //Linha 4 - Os estados de aceitacao
    readEndStates(stateList);
    //Linha 5 e 6 - O numero de transicoes e as transicoes entre os estados
    readTransitions(stateList);
    //Linha 7 e 8 - Le as cadeias de entrada, e verifica se a linguagem é reconhecida pelo automato ou nao
    int totalStringsToRead = readStringQuantity();
    readAndVerifyAllStrings(stateList,totalStringsToRead);
    
    //Libera a lista e o conjunto sigma
    for(int i = 0; i < totalStates; i++)
    {
        freeLinkedList(stateList[i]);
    }
    free(sigma);
}