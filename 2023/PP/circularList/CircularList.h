#ifndef CIRCULARLIST_CIRCULARLIST_H
#define CIRCULARLIST_CIRCULARLIST_H

#include "Node.h"

template < class nodeType = unsigned >
class DoubleCircularList {
  protected:
    Node<nodeType> *getList();
    void setList(Node<nodeType> *list);

  private:
    Node<nodeType> *ptr;
    void pushBack(nodeType data, Node<nodeType> **currentNode);

  public:
    DoubleCircularList();
    void pushBack(nodeType data);
    void popFront();
    nodeType front();
};

#include "CircularList.cpp"

#endif // CIRCULARLIST_CIRCULARLIST_H