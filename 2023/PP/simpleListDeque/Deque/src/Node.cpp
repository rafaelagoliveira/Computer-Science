#ifndef SIMPLELISTDEQUE_NODE_CPP
#define SIMPLELISTDEQUE_NODE_CPP

#include "Node.h"

template <class nodeType>
Node<nodeType>::Node(nodeType data, Node<nodeType> *next) : data(data), next(next) {}

template <class nodeType>
nodeType Node<nodeType>::getData() const {
    return data;
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
void Node<nodeType>::setNext(const Node<nodeType> *next) {
    this->next = next;
}

#endif // SIMPLELISTDEQUE_NODE_CPP