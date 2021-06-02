#include "operation.h"

// linha1
int readStatesQuantity()
{
    int quantity;
    while(1)
    {
        scanf("%d", &quantity);
        if(quantity > 0 && quantity < 11)
            break;
        else
            printf("Valor fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
    fflush(stdin);
    return quantity;
}

//Linha 2
void readSymbols(char *sigma)
{   
    char trash;
    int symbolQuantity;
    scanf("%d", &symbolQuantity);
    for(int i = 0; i < symbolQuantity; i++)
    {
        scanf("%c", &trash);
        scanf("%c", &sigma[i]);
    }
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
            for(int i = 0; i < totalInitialStates; i++)
            {
                stateList[i]->isInitialState = 1;
            }
            break;
        }
        else
            printf("Quantidade de estados iniciais fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
    fflush(stdin);
}

// Linha 4
void readEndStates(node **stateList)
{
    int totalEndStates = 0;
    char trash, endState;
    scanf("%d", &totalEndStates);
    for(int i = 0; i < totalEndStates; i++){
        scanf("%c", &trash);
        scanf("%c", &endState);
        //Convertendo o char para int
        int index  = endState - '0';
        stateList[index]->isEndState = 1;
    }
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
    return totalTransitions;
}

int isValueASymbol(char *value, char *sigma)
{
    for(int i = 0; i < 10; i++)
    {
        if(sigma[i] == value[0])
        {
            return 1;
        }
    }
    return 0;
}

// Linha 5 e 6
void readTransitions(node **stateList)
{
    char trash;
    int totalTransitions = readTransition();
    transition_t *transition = (transition_t*)malloc(totalTransitions * (sizeof(transition_t)));
    //linha 6
    //CRIAR UMA CONDICAO DE NAO PERMITIR INSERIR UM TERMINAL QUE NAO PERTENCA AO SIGMA
    for(int i = 0; i < totalTransitions; i++)
    {
        fflush(stdin);
        scanf("%c", &transition[i].currentState);
        scanf("%c", &trash);
        scanf("%c", &transition[i].transitionValue);
        scanf("%c", &trash);
        scanf("%c", &transition[i].nextState);
        int currentState= transition[i].currentState - '0';
        int nextState = transition[i].nextState - '0';
        pushNode(stateList[currentState],nextState,transition[i].transitionValue);
    }
    free(transition);

}

//linha 7
int readStringQuantity()
{
    char trash;
    int totalStrings;
    while(1){
        fflush(stdin);
        scanf("%d", &totalStrings);
        scanf("%c", &trash);
        if(totalStrings > 0 && totalStrings < 11)
            break;
        else
            printf("Numero de cadeias fora do intervalo 1<=n<=10. Informe outro numero.\n");
    }

    return totalStrings;
}

// // //linha 8
// int readAllInputString(inputString **strings, int totalStrings)
// {    
//     //linha 8
//     for(int i = 0; i < totalStrings; i++)
//     {
//         fflush(stdin);
//         scanf("%s",strings[i]->value);
//     }
// }

