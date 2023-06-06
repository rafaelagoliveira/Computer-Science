#ifndef SIMPLELISTDEQUE_DEQUE_CPP
#define SIMPLELISTDEQUE_DEQUE_CPP

#include "Deque.h"

template <class nodeType>
Deque<nodeType>::Deque() : ptr(nullptr) {}

template <class nodeType>
Deque<nodeType>::~Deque() {
    while (ptr != nullptr) {
        popFront();
    }
}

template <class nodeType>
void Deque<nodeType>::pushFront(nodeType data) {
    ptr = new Node<nodeType>(data, ptr);
    ++size;
}

template <class nodeType>
void Deque<nodeType>::pushBack(nodeType data, Node<nodeType> **currentNode) {
    if ((*currentNode) == nullptr) {
        *currentNode = new Node<nodeType>(data);
    } else {
        pushBack(data, &(*currentNode)->getNext());
    }
}

template <class nodeType>
void Deque<nodeType>::pushBack(nodeType data) {
    pushBack(data, &ptr);
    ++size;
}

template <class nodeType>
void Deque<nodeType>::popFront() {
    if (ptr != nullptr) {
        Node<nodeType> *temp = ptr;
        ptr = ptr->getNext();
        delete temp;
        --size;
    } else {
        throw(myExcept) POPFRONT_EXC;
    }
}

template <class nodeType>
void Deque<nodeType>::popBack(Node<nodeType> *&currentNode) {
    if (currentNode->getNext() == nullptr) {
        delete currentNode;
        currentNode = nullptr;
    } else {
        popBack(currentNode->getNext());
    }
}

template <class nodeType>
void Deque<nodeType>::popBack() {
    if (ptr != nullptr) {
        popBack(ptr);
        --size;
    } else {
        throw(myExcept) POPBACK_EXC;
    }
}

template <class nodeType>
nodeType Deque<nodeType>::getFront() const {
    if (ptr != nullptr) {
        return ptr->getData();
    } else {
        throw(myExcept) FRONT_EXC;
    }
}

template <class nodeType>
nodeType Deque<nodeType>::getBack(Node<nodeType> *currentNode) const {
    if (currentNode->getNext() == nullptr) {
        return currentNode->getData();
    }
    return getBack(currentNode->getNext());
}

template <class nodeType>
nodeType Deque<nodeType>::getBack() const {
    if (ptr != nullptr) {
        return getBack(ptr);
    } else {
        return (myExcept)BACK_EXC;
    }
}

template <class nodeType>
nodeType Deque<nodeType>::getInfo(int position, Node<nodeType> *currentNode) const {
    if (currentNode == nullptr) {
        return nodeType();
    } else if (position == 0) {
        return currentNode->getData();
    }
    return getInfo(position - 1, currentNode->getNext());
}

template <class nodeType>
nodeType Deque<nodeType>::getInfo(int position) const {
    return getInfo(position, ptr);
}

template <class nodeType>
unsigned int Deque<nodeType>::getSize() const {
    return size;
}

#endif // SIMPLELISTDEQUE_DEQUE_CPP