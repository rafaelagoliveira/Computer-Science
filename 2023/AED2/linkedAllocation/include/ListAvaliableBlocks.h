#ifndef LINKEDALLOCATION_LISTAVALIABLEBLOCKS_H
#define LINKEDALLOCATION_LISTAVALIABLEBLOCKS_H

#include "Node.h"

SimpleNode *initializeListAvaliableBlocks();
SimpleNode *searchListAvaliableBlocks(SimpleNode **ptr, int tBytes);
SimpleNode *searchByIAListAvaliableBlocks(SimpleNode **ptr, int iA);
SimpleNode *searchByEAListAvaliableBlocks(SimpleNode **ptr, int eA);
SimpleNode *deallocateListAvaliableBlocks(SimpleNode **ptr);
void insertListAvaliableBlocks(SimpleNode **ptr, int initialAddress, int bSize);
void removeListAvaliableBlocks(SimpleNode **ptr, int initialAddress);


#endif // LINKEDALLOCATION_LISTAVALIABLEBLOCKS_H