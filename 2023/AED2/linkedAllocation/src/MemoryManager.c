#include "MemoryManager.h"
#include "ListAllocatedBlocks.h"
#include "ListAvaliableBlocks.h"
#include <stdio.h>
#include <stdlib.h>

// Gerador de id
int idGenerator() {
    static int id = DEFAULT_ID;

    return ++id;
}

// Calcula o total de bytes alocados
int totalBytesAllocated(DoubleNode *allocatedBlocks) {
    int total = 0;

    while (allocatedBlocks != nullptr) {
        total += ((allocatedBlocks->endAddress - allocatedBlocks->initialAddress) + 1);
        allocatedBlocks = allocatedBlocks->next;
    }

    return total;
}

// Calcula o percentual de uso da memória
int percentageUsage(DoubleNode *allocatedBlocks, int mBytes) {
    int bytesAllocated = totalBytesAllocated(allocatedBlocks);
    return (bytesAllocated * 100) / mBytes;
}

// Realiza a alocação de memória
void allocation(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks, int tBytes, int mBytes) {
    // Verifica a existência de blocos disponíveis
    SimpleNode *avaliableNode = searchListAvaliableBlocks(avaliableBlocks, tBytes);

    if (avaliableNode == nullptr) {
        return;
    }

    int newId = idGenerator();
    int newInitialAddressAllocatedBlocks = avaliableNode->initialAddress;
    int newEndAddressAllocatedBlocks = newInitialAddressAllocatedBlocks + (tBytes - 1);
    int newBSize, newInitialAddressAvaliableBlocks;

    if (tBytes != avaliableNode->bSize) { // Se o tamanho do bloco a ser alocado for diferente do tamanho do bloco disponível
        newBSize = avaliableNode->bSize - tBytes;
        newInitialAddressAvaliableBlocks = mBytes - newBSize;
        removeListAvaliableBlocks(avaliableBlocks, avaliableNode->initialAddress);
        insertListAvaliableBlocks(avaliableBlocks, newInitialAddressAvaliableBlocks, newBSize);
    } else { // Se o tamanho do bloco a ser alocado for igual ao tamanho do bloco disponível
        removeListAvaliableBlocks(avaliableBlocks, avaliableNode->initialAddress);
    }

    insertListAllocatedBlocks(allocatedBlocks, newInitialAddressAllocatedBlocks, newEndAddressAllocatedBlocks, newId);
}

// Realiza a desalocação de memória
void deallocation(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks, int idBlock) {
    // Verifica se o bloco a ser desalocado existe
    DoubleNode *allocatedNode = searchListAllocatedBlocks(allocatedBlocks, idBlock);

    if (allocatedNode == nullptr) {
        return;
    }

    // Vefica se o endereco inicial do bloco a ser desalocado é igual à algum bsize da lista de blocos disponíveis
    SimpleNode *checkBSizeInitial = searchByIAListAvaliableBlocks(avaliableBlocks, allocatedNode->initialAddress);
    // Vefica se o endereco final do bloco a ser desalocado é igual à algum endereço inicial da lista de blocos disponíveis
    SimpleNode *checkBSizeEnd = searchByEAListAvaliableBlocks(avaliableBlocks, allocatedNode->endAddress + 1);

    // Calcula o total de bytes a serem desalocados
    int amountBytes = ((allocatedNode->endAddress - allocatedNode->initialAddress) + 1);
    int newBsize, newInitialAddress;

    if (checkBSizeInitial != nullptr && checkBSizeEnd != nullptr) { // O bloco a ser desalocado está entre dois blocos disponíveis
        newBsize = checkBSizeInitial->bSize + checkBSizeEnd->bSize + amountBytes;
        newInitialAddress = checkBSizeInitial->initialAddress;
        removeListAvaliableBlocks(avaliableBlocks, checkBSizeInitial->initialAddress);
        removeListAvaliableBlocks(avaliableBlocks, checkBSizeEnd->initialAddress);
        insertListAvaliableBlocks(avaliableBlocks, newInitialAddress, newBsize);
    } else if (checkBSizeInitial != nullptr) { // O bloco a ser desalocado está no atrás de um bloco disponível
        newBsize = checkBSizeInitial->bSize + amountBytes;
        newInitialAddress = allocatedNode->initialAddress;
        removeListAvaliableBlocks(avaliableBlocks, checkBSizeInitial->initialAddress);
        insertListAvaliableBlocks(avaliableBlocks, newInitialAddress, newBsize);
    } else if (checkBSizeEnd != nullptr) { // O bloco a ser desalocado está na frente de um bloco disponível
        newBsize = checkBSizeEnd->bSize + amountBytes;
        newInitialAddress = allocatedNode->initialAddress;
        removeListAvaliableBlocks(avaliableBlocks, checkBSizeEnd->initialAddress);
        insertListAvaliableBlocks(avaliableBlocks, newInitialAddress, newBsize);
    } else {
        insertListAvaliableBlocks(avaliableBlocks, allocatedNode->initialAddress, amountBytes);
    }

    removeListAllocatedBlocks(allocatedBlocks, idBlock);
}

// Realiza a desalocação de todos os blocos
void deallocationAllBlocks(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks) {
    if (*avaliableBlocks == nullptr && *allocatedBlocks == nullptr) {
        return;
    } else if (*avaliableBlocks != nullptr) {
        *avaliableBlocks = deallocateListAvaliableBlocks(avaliableBlocks);
    } else {
        *allocatedBlocks = deallocateListAllocatedBlocks(allocatedBlocks);
    }
}