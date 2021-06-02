#include "linkedList.h"


//void create_node()
int pushNode(node *header, int state, char value)
{
    node *aux = header;
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    node *new_node = (node*)malloc(sizeof(node));
    new_node->state = state;
    new_node->value = value;
    new_node->next = NULL;
    aux->next = new_node;

    return 1;
}

//Liberar todos os Nodes da lista
void free_linkedList(node *header){
    node *aux_node;
    while(header != NULL){
        aux_node = header;
        header = header->next;
        free(aux_node);
    }
}

node *createLinkedList()
{
    node *header = (node*)malloc(sizeof(node));
    header->next = NULL;
    header->state = -1;
    header->value = '-';
    
    return header;
}

void printNode(node **linkedList)
{
    for(int i = 0; i < 3; i++)
    {
        node *aux = linkedList[i]->next;
        while(aux != NULL)
        {
            printf("state:%d -> state: %d value: %c\n",i,aux->state,aux->value);
            aux = aux->next;
        }
        printf("-----------------\n");
    }
}
