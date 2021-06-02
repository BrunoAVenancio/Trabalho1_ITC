#include "acceptStateHandler.h"

void funcaoRecursiva(node **linkedList, char *input_string)
{
    //Passo o array de estados com os paths de cada um deles
    //Depois comeco com o estado inicial
    //Ai entro em uma funcao recursiva, que retorna false ou true para indicar se existe ou nao
    //Nessa funcao recursica devo verificar todos os paths possivel de cada estado, logo, preciso verificar na toda lista de
    //cada estado, para ver se existe o terminal que desejo e, com isso, se tiver ele entra em uma funcao com esse node, ai a lista
    // vai ate quando chegar no NULL
    
}

//ta tudo desorganizado , me desculpe
//por enquanto so um estado final, depois implemento o codigo com mais de um estado final
int hasPath(node **linkedList,int current_state ,char *input_string, int string_index, int end_state, int isPossible)
{
    //ver os caminhos
    node *aux = linkedList[current_state]->next;
    while(aux != NULL && isPossible == 0 && string_index < strlen(input_string))
    {
        printf("{%d,%d}%c\n",current_state,aux->state,aux->value);
        if(aux->value == input_string[string_index])
        {
            printf("%lu e %d\n",strlen(input_string),string_index);
            if(strlen(input_string) == string_index + 1 && end_state == aux->state)
            {
                            printf("%lu\n",strlen(input_string));
                return 1; // Eh possivel a entrada
            }
            isPossible = hasPath(linkedList, aux->state, input_string, string_index+1, end_state, isPossible);
        }
        aux = aux->next;
    }
    //

    return isPossible;
}
