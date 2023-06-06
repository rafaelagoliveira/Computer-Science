#ifndef LINKEDALLOCATION_MEMORYMANAGER_H
#define LINKEDALLOCATION_MEMORYMANAGER_H

#include "ListAvaliableBlocks.h"
#include "ListAllocatedBlocks.h"

#define DEFAULT_ID 0

int percentageUsage(DoubleNode *allocatedBlocks, int mBytes);
void allocation(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks, int tBytes, int mBytes);
void deallocation(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks, int idBlock);
void deallocationAllBlocks(SimpleNode **avaliableBlocks, DoubleNode **allocatedBlocks);

#endif // LINKEDALLOCATION_MEMORYMANAGER_H