#ifndef SIMPLELISTDEQUE_NODE_H
#define SIMPLELISTDEQUE_NODE_H

template <class nodeType = int>
class Node {
  private:
    nodeType data;
    Node<nodeType> *next;

  public:
    Node(nodeType data = nodeType(), Node<nodeType> *next = nullptr);
    nodeType getData() const;
    Node<nodeType> *&getNext();
    void setData(const nodeType data);
    void setNext(const Node<nodeType> *next);
};

#include "Node.cpp"

#endif // SIMPLELISTDEQUE_NODE_H