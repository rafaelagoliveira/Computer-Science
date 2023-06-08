#ifndef CIRCULARLIST_ROULETTE_H
#define CIRCULARLIST_ROULETTE_H

#include "CircularList.h"

template <class nodeType = unsigned>
class Roulette : public DoubleCircularList<> {
  private:
    unsigned sizeList, stops;
    DoubleCircularList<> list;
    void rotateClockWise(unsigned stops);

  public:
    Roulette(unsigned t, unsigned p);
    void setSizeList(unsigned sizeList);
    void setStops(unsigned stops);
    unsigned turnsRoulette();
};

#include "Roulette.cpp"

#endif // CIRCULARLIST_ROULETTE_H