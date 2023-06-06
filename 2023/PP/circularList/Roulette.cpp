#ifndef CIRCULARLIST_ROULETTE_CPP
#define CIRCULARLIST_ROULETTE_CPP

#include "Roulette.h"

template <class nodeType>
Roulette<nodeType>::Roulette(unsigned sizeList, unsigned stops) : sizeList(sizeList), stops(stops) {}

template <class nodeType>
void Roulette<nodeType>::setSizeList(unsigned sizeList) {
    this->sizeList = sizeList;
}

template <class nodeType>
void Roulette<nodeType>::setStops(unsigned stops) {
    this->stops = stops;
}

template <class nodeType>
void Roulette<nodeType>::rotateClockWise(unsigned stops) {
    for (int i = 0; i < stops; ++i) {
        list.setList(list.getNext());
    }
}

template <class nodeType>
unsigned Roulette<nodeType>::turnsRoulette() {
    for (int i = 1; i < sizeList; ++i) {
        list.pushBack(i);
    }
    for (int i = sizeList - 1; i > 0; --i) {
        rotateClockWise(stops - 1);
        list.popFront();
    }

    return list.front();
}

#endif // CIRCULARLIST_ROULETTE_CPP