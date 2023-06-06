#ifndef LINKEDALLOCATION_NODE_H
#define LINKEDALLOCATION_NODE_H

#ifndef NULL
#undef NULL
#endif

#define nullptr ((void *)0)

// Estrutura de um nó simples
typedef struct SimpleNode {
    int initialAddress, bSize;
    struct SimpleNode *next;
} SimpleNode;

// Estrutura de um nó duplo
typedef struct DoubleNode {
    int initialAddress, endAddress, id;
    struct DoubleNode *previous, *next;
} DoubleNode;

SimpleNode *createSimpleNode(int initialAddress, int bSize);
DoubleNode *createDoubleNode(int initialAddress, int endAdress, int id);

#endif // LINKEDALLOCATION_NODE_H