#ifndef CIRCULARLIST_CIRCULARLIST_CPP
#define CIRCULARLIST_CIRCULARLIST_CPP

#include "CircularList.h"

template <class nodeType>
Node<nodeType> *DoubleCircularList<nodeType>::getList() {
    return ptr;
}

template <class nodeType>
void DoubleCircularList<nodeType>::setList(Node<nodeType> *list) {
    this->ptr = list;
}

template <class nodeType>
DoubleCircularList<nodeType>::DoubleCircularList() : ptr(nullptr) {}

template <class nodeType>
void DoubleCircularList<nodeType>::pushBack(nodeType data, Node<nodeType> **currentNode) {
    if (*currentNode == nullptr) {
        *currentNode = new Node<nodeType>(data);

        (*currentNode)->setNext(ptr);
        (*currentNode)->setPrevius(ptr->getPrevius());

        ptr->setPrevius(*currentNode);
        ptr->getPrevius()->setNext(*currentNode);
    } else {
        pushBack(data, &(*currentNode)->getNext());
    }
}

template <class nodeType>
void DoubleCircularList<nodeType>::pushBack(nodeType data) {
    pushBack(data, &ptr);
}

template <class nodeType>
void DoubleCircularList<nodeType>::popFront() {
    if (ptr != nullptr) {
        Node<nodeType> *temp = ptr;
        ptr = ptr->getNext();
        delete temp;
    } else {
        return;
    }
}

template <class nodeType>
nodeType DoubleCircularList<nodeType>::front() {
    return ptr->getData();
}

#endif // CIRCULARLIST_CIRCULARLIST_CPP