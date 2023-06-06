#ifndef LINKEDALLOCATION_GRAPHICINTERFACE_H
#define LINKEDALLOCATION_GRAPHICINTERFACE_H

#include "../gfx/gfx.h"
#include "Node.h"
#include "ListAvaliableBlocks.h"
#include "ListAllocatedBlocks.h"
#include "MemoryManager.h"

#define WIDTH 1024 // largura da tela
#define HEIGHT 768 // altura da tela

void background(); // Desenha o background
void gfxShowMemoryManager(SimpleNode *listAvaliable, DoubleNode *listAllocated, int mBytes); // Desenha o gerenciador de memoria

#endif // LINKEDALLOCATION_GRAPHICINTERFACE_H