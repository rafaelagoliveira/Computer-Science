#ifndef SIMPLELIST_NODE_CPP
#define SIMPLELIST_NODE_CPP

#include "Node.h"

template <class nodeType>
Node<nodeType>::Node(nodeType data, Node<nodeType> *previus, Node<nodeType> *next)
    : data(data), previus(previus), next(next) {}

template <class nodeType>
nodeType Node<nodeType>::getData() const {
    return data;
}

template <class nodeType>
Node<nodeType> *&Node<nodeType>::getPrevius() {
    return previus;
}

template <class nodeType>
Node<nodeType> *&Node<nodeType>::getNext() {
    return next;
}

template <class nodeType>
void Node<nodeType>::setData(const nodeType data) {
    this->data = data;
}

template <class nodeType>
void Node<nodeType>::setPrevius(Node<nodeType> *previus) {
    this->previus = previus;
}

template <class nodeType>
void Node<nodeType>::setNext(Node<nodeType> *next) {
    this->next = next;
}

#endif // SIMPLELIST_NODE_CPP