#include "Point.h"

//Getters
float Point::getx() const {
    return x;
}

float Point::gety() const {
    return y;
}

//Setters
void Point::setx(float x) {
    this->x = x;
}

void Point::sety(float y) {
    this->y = y;
}

//Metodo de calculo
float Point::distance(const Point &other) const {
    return sqrt( pow(x - other.x, 2) + pow(y - other.y, 2) );
}
