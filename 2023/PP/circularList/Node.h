#ifndef CIRCULARLIST_NODE_H
#define CIRCULARLIST_NODE_H

#include <iostream>

template <class nodeType >
class Node {
  private:
    nodeType data;
    Node<nodeType> *previus, *next;

  public:
    Node(nodeType data = nodeType(), Node<nodeType> *previus = nullptr, Node<nodeType> *next = nullptr);
    nodeType getData() const;
    Node<nodeType> *&getPrevius();
    Node<nodeType> *&getNext();
    void setData(const nodeType data);
    void setPrevius(Node<nodeType> *previus);
    void setNext(Node<nodeType> *next);
};

#include "Node.cpp"

#endif // CIRCULARLIST_NODE_H