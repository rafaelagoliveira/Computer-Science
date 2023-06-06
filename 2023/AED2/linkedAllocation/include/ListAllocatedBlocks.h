#ifndef LINKEDALLOCATION_LISTALLOCATEDBLOCKS_H
#define LINKEDALLOCATION_LISTALLOCATEDBLOCKS_H

#include "Node.h"

DoubleNode *initializeListAllocatedBlocks();
DoubleNode *searchListAllocatedBlocks(DoubleNode **list, int id);
DoubleNode *deallocateListAllocatedBlocks(DoubleNode **ptr);
void insertListAllocatedBlocks(DoubleNode **ptr, int initialAddress, int endAddress, int id);
void removeListAllocatedBlocks(DoubleNode **ptr, int id);  

#endif // LINKEDALLOCATION_LISTALLOCATEDBLOCKS_H