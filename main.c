#include "acceptStateHandler.h"
#include "operation.h"

int main()
{
    //Linha 1 - Numero de estados
    int totalStates = readStatesQuantity();
    node *stateList[totalStates];

	int i = 0;
    for (i = 0; i < totalStates; i++)
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
    readTransitions(stateList, sigma);

    //Linha 7 e 8 - Le as cadeias de entrada, e verifica se a linguagem Ã© reconhecida pelo automato ou nao
    int totalStringsToRead = readStringQuantity();
    readAndVerifyAllStrings(stateList,totalStringsToRead);

    //Libera a lista e o conjunto sigma
    for (i = 0; i < totalStates; i++)
    {
        freeLinkedList(stateList[i]);
    }

    free(sigma);

	setbuf(stdin, NULL);
	printf("Aperte qualquer tecla para encerrar o simulador.\n");
	// getch();

    return 0;
}