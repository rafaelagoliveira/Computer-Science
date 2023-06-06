#include "Node.h"
#include <stdlib.h>

// Cria um nó na lista de blocos disponíveis
SimpleNode *createSimpleNode(int initialAddress, int bSize) {
    SimpleNode *newNode = (SimpleNode *) malloc(sizeof(SimpleNode));
 
    newNode->initialAddress = initialAddress;
    newNode->bSize = bSize;
    newNode->next = NULL;
 
    return newNode;
}

// Cria um nó na lista de blocos alocados
DoubleNode *createDoubleNode(int initialAddress, int endAddress, int id) {
    DoubleNode *newNode = (DoubleNode *) malloc(sizeof(DoubleNode));
 
    newNode->initialAddress = initialAddress;
    newNode->endAddress = endAddress;
    newNode->id = id;
    newNode->previous = newNode->next = NULL;
 
    return newNode;
}
