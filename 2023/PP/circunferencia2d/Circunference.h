#ifndef CIRCUNFERENCE_H_INCLUDED
#define CIRCUNFERENCE_H_INCLUDED

#include "Point.h"

class Circunference {
private:
    Point center;
    float radius;

public:
    //Setters
    void setPosition(float x, float y);
    void setRadius(float radius);

    // Metodo de calculo
    float distance(const Circunference &other) const;
};

#endif //CIRCUNFERENCE_H_INCLUDED