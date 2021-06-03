#include "linkedList.h"

//cria os nodes para a linked List
node *createLinkedList()
{
    node *header = (node*)malloc(sizeof(node));

    header->next = NULL;
    header->nextStateName = -1;
    header->transitionValue = '-';
    header->isEndState = 0;
    header->isInitialState = 0;

    return header;
}

//Liberar todos os Nodes da lista
void freeLinkedList(node *header)
{
    node *auxNode;
    while (header != NULL)
    {
        auxNode = header;
        header = header->next;
        free(auxNode);
    }
}

int pushNode(node *header, int state, char value)
{
    node *aux = header;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    node *newNode = (node*) malloc(sizeof(node));
    newNode->nextStateName = state;
    newNode->transitionValue = value;
    newNode->next = NULL;
    aux->next = newNode;

    return 1;
}