#include "ListAvaliableBlocks.h"
#include <stdio.h>
#include <stdlib.h>

// Inicializa a lista
SimpleNode *initializeListAvaliableBlocks() {
    return nullptr;
}

// Desaloca a lista
SimpleNode *deallocateListAvaliableBlocks(SimpleNode **ptr) {
    if (*ptr == nullptr) {
        return *ptr;
    }

    return deallocateListAvaliableBlocks(&(*ptr)->next);
    free(*ptr);
}

// Procura um bloco disponível na lista
SimpleNode *searchListAvaliableBlocks(SimpleNode **ptr, int tBytes) {
    if (*ptr == nullptr) {
        return nullptr;
    } else if (tBytes <= (*ptr)->bSize) {
        return *ptr;
    } else {
        return searchListAvaliableBlocks(&(*ptr)->next, tBytes);
    }
}

// Procura um bloco disponível na lista pelo endereço inicial(parametro)
SimpleNode *searchByIAListAvaliableBlocks(SimpleNode **ptr, int iA) {
    if (*ptr == nullptr) {
        return nullptr;
    } else if (iA == (*ptr)->bSize) {
        return *ptr;
    } else {
        return searchListAvaliableBlocks(&(*ptr)->next, iA);
    }
}

// Procura um bloco disponível na lista pelo endereço final(parametro)
SimpleNode *searchByEAListAvaliableBlocks(SimpleNode **ptr, int eA) {
    if (*ptr == nullptr) {
        return nullptr;
    } else if (eA == (*ptr)->initialAddress) {
        return *ptr;
    } else {
        return searchListAvaliableBlocks(&(*ptr)->next, eA);
    }
}

// Insere um bloco disponível na lista
void insertListAvaliableBlocks(SimpleNode **ptr, int initialAddress, int bSize) {
    SimpleNode *newNode = createSimpleNode(initialAddress, bSize);
    
    if (*ptr == nullptr) {
        *ptr = newNode;
    } else if (bSize < (*ptr)->bSize) {
        newNode->next = *ptr;
        *ptr = newNode;
    } else {
        SimpleNode *currentNode = *ptr;

        while (currentNode->next != nullptr && bSize >= currentNode->next->bSize) {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

// Remove um bloco disponível na lista
void removeListAvaliableBlocks(SimpleNode **ptr, int initialAddress) {
    if (*ptr == nullptr) {
        return;
    } else if (initialAddress == (*ptr)->initialAddress) {
        SimpleNode *aux = *ptr;
        *ptr = (*ptr)->next;
        aux->next = nullptr;
        free(aux);
    } else {
        removeListAvaliableBlocks(&(*ptr)->next, initialAddress);
    }
}
