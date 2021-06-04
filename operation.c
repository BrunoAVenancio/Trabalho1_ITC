#include "operation.h"

// linha1
int readStatesQuantity()
{
    int quantity;
    while(1)
    {
        scanf("%d", &quantity);
        if (quantity > 0 && quantity < 11)
            break;
        else
            printf("Valor fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
    setbuf(stdin, NULL);
    return quantity;
}

//Linha 2
void readSymbols(char *sigma)
{
    char trash;
    int symbolQuantity;
    scanf("%d", &symbolQuantity);

    int i = 0;
    for (i = 0; i < symbolQuantity && i < 10; i++)
    {
        scanf("%c", &trash);
        scanf("%c", &sigma[i]);
    }
    if(symbolQuantity > 10)
    {
        for(int j=10; j < symbolQuantity; j++)
        {
            scanf("%c", &trash);
            scanf("%c", &trash);
        }
        printf("Entradas além de 10 nao foram salvas!\n");
    }
    getchar();
}

// Linha 3
void readInitialStates(node **stateList)
{
    int totalInitialStates = 0;
    while(1)
    {
        fflush(stdin);
        scanf("%d", &totalInitialStates);
        if(totalInitialStates > 0 && totalInitialStates < 11)
        {
        	int i = 0;
            for (i = 0; i < totalInitialStates; i++)
            {
                stateList[i]->isInitialState = 1;
            }
            break;
        }
        else
            printf("Quantidade de estados iniciais fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
    getchar();
}

// Linha 4
void readEndStates(node **stateList)
{
    int totalEndStates = 0;
    char trash, endState;
    scanf("%d", &totalEndStates);

    int i = 0;
    for (i = 0; i < totalEndStates && i < 10; i++)
    {
        scanf("%c", &trash);
        scanf("%c", &endState);
        //Convertendo o char para int
        int index  = endState - '0';
        stateList[index]->isEndState = 1;
    }
    if(totalEndStates > 10)
    {
        for(int j = 10; j < totalEndStates; j++)
        {
            scanf("%c", &trash);
            scanf("%c", &trash);
        }
        printf("Entradas além de 10 nao foram salvas!\n");
    }
    getchar();
}

//linha 5
int readTransition()
{
    int totalTransitions = 0;
    while(1)
    {
        fflush(stdin);
        scanf("%d", &totalTransitions);
        if(totalTransitions > 0 && totalTransitions < 51)
            break;
        else
            printf("Numero de transicoes fora do intervalo 1<=n<=50. Informe outro valor.\n");

    }
    getchar();
    return totalTransitions;
}

int isValueASymbol(char *value, char *sigma)
{
	int i = 0;
    for (i = 0; i < 10; i++)
    {
        if (sigma[i] == value[0])
        {
            return 1;
        }
    }
    return 0;
}

// Linha 5 e 6
void readTransitions(node **stateList, char *sigma)
{
    char trash;
    int totalTransitions = readTransition();

    transition_t *transition = (transition_t*)malloc(totalTransitions * (sizeof(transition_t)));

    //linha 6
    //CRIAR UMA CONDICAO DE NAO PERMITIR INSERIR UM TERMINAL QUE NAO PERTENCA AO SIGMA
    int i = 0;
	for (i = 0; i < totalTransitions; i++)
    {
        int controller = 0;
        while (controller == 0)
        {
            fflush(stdin);
            scanf("%c", &transition[i].currentState);
            scanf("%c", &trash);
            scanf("%c", &transition[i].transitionValue);
            scanf("%c", &trash);
            scanf("%c", &transition[i].nextState);
            getchar();
            if (!isValueASymbol(&transition[i].transitionValue, sigma))
            {
                printf("Valor de transicao invalido (nao pertencente a sigma). Tente novamente.\n");
                controller = 0;
            }
            else
            {
                controller = 1;
                int currentState= transition[i].currentState - '0';
                int nextState = transition[i].nextState - '0';

                pushNode(stateList[currentState],nextState,transition[i].transitionValue);
            }
        }
    }
    free(transition);
}

//linha 7
int readStringQuantity()
{
    char trash;
    int totalStrings;

    while (1)
    {
        setbuf(stdin, NULL);
        scanf("%d", &totalStrings);
        scanf("%c", &trash);
        if(totalStrings > 0 && totalStrings < 11)
            break;
        else
            printf("Numero de cadeias fora do intervalo 1<=n<=10. Informe outro numero.\n");
    }

    return totalStrings;
}
