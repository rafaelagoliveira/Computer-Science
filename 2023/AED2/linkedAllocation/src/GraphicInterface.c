#include "GraphicInterface.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LabelAvaliableNode {
    char iA[10];
    char b[10];
} AvaliableNode;

typedef struct LabelAllocatedNode {
    char iA[10];
    char eA[10];
    char id[10];
} AllocatedNode;

typedef struct LimitCoordinates {
    int xMin;
    int xMax;
    int yMin;
    int yMax;
} XYLimiter;

typedef struct Coordinates {
    int xI;
    int xF;
    int yI;
    int yF;
    XYLimiter limiter;
} Coordinates;

void background() {
    gfx_clear();                              // Limpa a tela
    gfx_set_color(40, 42, 54);                // Define a cor do background
    gfx_filled_rectangle(0, 0, WIDTH, WIDTH); // Desenha o background
}

// Inicializa as coordenadas padrões
void initializeDefaultCoordinates(Coordinates *pAvaliable, Coordinates *pAllocated) {
    pAllocated->limiter.xMin = 20;
    pAllocated->limiter.xMax = WIDTH - 20;
    pAllocated->limiter.yMin = 20;
    pAllocated->limiter.yMax = HEIGHT - 20;
    pAllocated->xI = 40;
    pAllocated->xF = 166;
    pAllocated->yI = 20;
    pAllocated->yF = 50;

    pAvaliable->limiter.xMin = 20;
    pAvaliable->limiter.xMax = WIDTH - 20;
    pAvaliable->limiter.yMin = (HEIGHT / 2) + 20;
    pAvaliable->limiter.yMax = HEIGHT - 20;
    pAvaliable->xI = 40;
    pAvaliable->xF = 166;
    pAvaliable->yI = (HEIGHT / 2) + 20;
    pAvaliable->yF = (HEIGHT / 2) + 50;
}

// Desenha a figura do nó
void drawFigure(Coordinates *point) {
    gfx_set_color(98, 114, 164);
    gfx_filled_rectangle(point->xI, point->yI + 2, point->xF, point->yF - 2);

    gfx_set_color(248, 248, 242);
    gfx_rectangle(point->xI, point->yI + 2, point->xF, point->yF - 2);

    gfx_set_color(123, 104, 238);
    gfx_filled_rectangle(point->xI + 3, point->yI, point->xF - 3, point->yF);

    gfx_set_color(248, 248, 242);
    gfx_rectangle(point->xI + 3, point->yI, point->xF - 3, point->yF);
}

// Desenha as repartições das informações do nó
void drawLabelAvaliableNode(Coordinates *point) {
    unsigned adjust = (point->xF - point->xI) / 2;
    gfx_set_color(248, 248, 242);
    gfx_line(point->xI + adjust, point->yI, point->xI + adjust, point->yF);
}

// Desenha as repartições das informações do nó
void drawLabelAllocatedNode(Coordinates *point) {
    unsigned adjust = (point->xF - point->xI) / 3;
    gfx_set_color(248, 248, 242); // Define a cor do texto
    gfx_line(point->xI + adjust, point->yI, point->xI + adjust, point->yF);
    gfx_line(point->xI + adjust * 2, point->yI, point->xI + adjust * 2, point->yF);
}

// Desenha o nó disponivel
void drawAvaliableNode(Coordinates *point, AvaliableNode *text, unsigned fontSize) {
    drawFigure(point);             // Desenha a figura do no
    drawLabelAvaliableNode(point); // Desenha a label do no
    gfx_set_color(248, 248, 242);  // Define a cor do texto
    gfx_set_font_size(fontSize);   // Define o tamanho do texto
    gfx_text(point->xI + 25, point->yI + 5, text->iA);
    gfx_text(point->xI + 85, point->yI + 5, text->b);
}

// Desenha o nó alocado
void drawAllocatedNode(Coordinates *point, AllocatedNode *text, unsigned fontSize) {
    drawFigure(point);             // Desenha a figura do no
    drawLabelAllocatedNode(point); // Desenha a label do no
    gfx_set_color(248, 248, 242);  // Define a cor do texto
    gfx_set_font_size(fontSize);   // Define o tamanho do texto
    gfx_text(point->xI + 14, point->yI + 5, text->iA);
    gfx_text(point->xI + 55, point->yI + 5, text->eA);
    gfx_text(point->xI + 98, point->yI + 5, text->id);
}

// Desenha a informação das listas
void drawLabelList(Coordinates *point, const char *text) {
    drawFigure(point);            // Desenha a figura do no
    gfx_set_color(248, 248, 242); // Define a cor do texto
    gfx_set_font_size(15);        // Define o tamanho do texto
    gfx_text(((point->xF - point->xI) / 2) - (unsigned)(strlen(text)), point->yI + 5, text);
}

// Desenha a informação dos blocos
void drawInformartionBlocks(Coordinates *point, const char *textIA, const char *textEA, const char *textID) {
    int adjust;

    drawFigure(point);            // Desenha a figura do no
    gfx_set_color(248, 248, 242); // Define a cor do texto
    gfx_set_font_size(15);        // Define o tamanho do texto

    if (textID != nullptr) {
        adjust = ((point->xF - point->xI) / 3);
        
        drawLabelAllocatedNode(point);

        gfx_text((point->xI + adjust) - 130, point->yI + 5, textIA);
        gfx_text((point->xI + adjust * 2) - 130, point->yI + 5, textEA);
        gfx_text((point->xI + adjust * 3) - 130, point->yI + 5, textID);
    } else {
        adjust = (point->xF - point->xI) / 2;
        
        gfx_text((point->xI + adjust) - 130, point->yI + 5, textIA);
        gfx_text((point->xI + adjust * 2) - 130, point->yI + 5, textEA);
        
        drawLabelAvaliableNode(point);
    }
}

// Desenha o percentual de memoria alocada
void gfxShowPecentualAllocated(Coordinates *point, int percentage) {
    drawFigure(point);            // Desenha a figura do no
    gfx_set_color(248, 248, 242); // Define a cor do texto
    gfx_set_font_size(15);        // Define o tamanho do texto

    char text[10];
    snprintf(text, 10, "%d%%", percentage);

    gfx_text(point->xI + 25, point->yI + 5, text);
    gfx_text(point->xI + 70, point->yI + 5, "Allocated");
}

// Informa sobre os detalhes da memoria
void gfxShowDetails(DoubleNode *allocatedBlocks, int mBytes) {
    Coordinates pAvaliable, pAllocated;

    initializeDefaultCoordinates(&pAvaliable, &pAllocated);

    pAvaliable.xI = pAvaliable.xF + 50;
    pAvaliable.xF = pAvaliable.xI + 332;

    pAllocated.xI = pAllocated.xF + 50;
    pAllocated.xF = pAvaliable.xI + 498;

    drawInformartionBlocks(&pAvaliable, "Initial Address", "Block Size", nullptr);
    drawInformartionBlocks(&pAllocated, "Initial Address", "End Address", "ID");

    pAvaliable.xI = pAvaliable.xF + 50;
    pAvaliable.xF = pAvaliable.xI + 166;

    gfxShowPecentualAllocated(&pAvaliable, (int)percentageUsage(allocatedBlocks, mBytes));
}

// Desenha a lista de blocos disponiveis
void gfxShowAvaliableBlocks(SimpleNode *node, Coordinates *point) {
    if (point->yI == point->limiter.yMin) {
        drawLabelList(point, "Avaliable Blocks");

        point->yI += 50;
        point->yF += 50;
    }

    if (node == nullptr) {
        return;
    }

    AvaliableNode text;

    snprintf(text.iA, 10, "%d", (node)->initialAddress);
    snprintf(text.b, 10, "%d", (node)->bSize);

    drawAvaliableNode(point, &text, 16);

    point->xI = point->xF;
    point->xF = point->xI + 126;

    if (node->next != nullptr && point->xF > point->limiter.xMax) {
        point->xI = 40;
        point->xF = 166;
        point->yI += 50;
        point->yF += 50;

        gfxShowAvaliableBlocks(node->next, point);
    } else {
        gfxShowAvaliableBlocks(node->next, point);
    }
}

// Desenha a lista de blocos alocados
void gfxShowAllocatedBlocks(DoubleNode *node, Coordinates *point) {
    if (point->yI == point->limiter.yMin) {
        drawLabelList(point, "Allocated Blocks");

        point->yI += 50;
        point->yF += 50;
    }

    if (node == nullptr) {
        return;
    }

    AllocatedNode text;

    snprintf(text.iA, 10, "%d", (node)->initialAddress);
    snprintf(text.eA, 10, "%d", (node)->endAddress);
    snprintf(text.id, 10, "%d", (node)->id);

    drawAllocatedNode(point, &text, 16);

    point->xI = point->xF;
    point->xF = point->xI + 126;

    if (node->next != nullptr && point->xF > point->limiter.xMax) {
        point->xI = 40;
        point->xF = 166;
        point->yI += 50;
        point->yF += 50;

        gfxShowAllocatedBlocks(node->next, point);
    } else {
        gfxShowAllocatedBlocks(node->next, point);
    }
}

// Desenha o gerenciador de memoria
void gfxShowMemoryManager(SimpleNode *listAvaliable, DoubleNode *listAllocated, int mBytes) {
    Coordinates startingPointAvaliableBlocks, startingPointAllocatedBlocks;

    initializeDefaultCoordinates(&startingPointAvaliableBlocks, &startingPointAllocatedBlocks);

    gfxShowDetails(listAllocated, mBytes);
    gfxShowAvaliableBlocks(listAvaliable, &startingPointAvaliableBlocks);
    gfxShowAllocatedBlocks(listAllocated, &startingPointAllocatedBlocks);
}
