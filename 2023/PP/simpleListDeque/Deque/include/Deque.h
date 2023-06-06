#ifndef SIMPLELISTDEQUE_DEQUE_H
#define SIMPLELISTDEQUE_DEQUE_H

#include "Node.h"

enum myExcept{FRONT_EXC, BACK_EXC, POPFRONT_EXC, POPBACK_EXC};

template <class nodeType = int>
class Deque {
  private:
    Node<nodeType> *ptr;
    unsigned int size;
    void pushBack(nodeType data, Node<nodeType> **currentNode);
    void popBack(Node<nodeType> *&currentNode);
    nodeType getBack(Node<nodeType> *currentNode) const;
    nodeType getInfo(int position, Node<nodeType> *currentNode) const;

  public:
    Deque();
    ~Deque();
    void pushFront(nodeType data);
    void pushBack(nodeType data);
    void popFront();
    void popBack();
    nodeType getFront() const;
    nodeType getBack() const;
    nodeType getInfo(int position) const;
    unsigned int getSize() const;
};

#include "Deque.cpp"

#endif // SIMPLELISTDEQUE_DEQUE_H