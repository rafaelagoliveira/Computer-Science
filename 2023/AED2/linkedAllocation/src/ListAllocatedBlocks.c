#include "ListAllocatedBlocks.h"
#include <stdlib.h>

// Inicializa a lista
DoubleNode *initializeListAllocatedBlocks() {
    return nullptr;
}

// Desaloca a lista
DoubleNode *deallocateListAllocatedBlocks(DoubleNode **ptr) {
    if (*ptr == nullptr) {
        return *ptr;
    }

    return deallocateListAllocatedBlocks(&(*ptr)->next);
    free(*ptr);
    *ptr = nullptr;
}

// Procura um bloco na lista
DoubleNode *searchListAllocatedBlocks(DoubleNode **ptr, int idBlock) {
    if (*ptr == nullptr) {
        return nullptr;
    } else if (idBlock == (*ptr)->id) {
        return *ptr;
    } else {
        return searchListAllocatedBlocks(&(*ptr)->next, idBlock);
    }
}

// Insere um bloco na lista
void insertListAllocatedBlocks(DoubleNode **ptr, int initialAddress, int endAddress, int idBlock) {
    DoubleNode *newNode = createDoubleNode(initialAddress, endAddress, idBlock);
    
    if (*ptr == nullptr) {
        *ptr = newNode;
    } else if (idBlock < (*ptr)->id) {
        newNode->next = *ptr;
        (*ptr)->previous = newNode;
    } else {
        DoubleNode *previousNode = *ptr;
        DoubleNode *currentNode = (*ptr)->next;
        
        while (currentNode != nullptr && idBlock > currentNode->id) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        newNode->next = currentNode;
        newNode->previous = previousNode;
        if (currentNode != nullptr) {
            currentNode->previous = newNode;
        }
        previousNode->next = newNode;
    }
}

// Remove um bloco da lista
void removeListAllocatedBlocks(DoubleNode **ptr, int idBlock) {
    if (*ptr == nullptr) {
        return;
    } else if (idBlock == (*ptr)->id) {
        DoubleNode *temp = *ptr;
        *ptr = (*ptr)->next;
        if (*ptr != nullptr) {
            (*ptr)->previous = temp->previous;
        }
        free(temp);
    } else {
        removeListAllocatedBlocks(&(*ptr)->next, idBlock);
    }
}