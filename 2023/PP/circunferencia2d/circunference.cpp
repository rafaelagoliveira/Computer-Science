#include "Circunference.h"

// Setters
void Circunference::setPosition(float x, float y) {
    center.setx(x);
    center.sety(y);
}

void Circunference::setRadius(float radius) {
    this->radius = radius;
}

// Metodo de calculo
float Circunference::distance(const Circunference &other) const {
    return center.distance(other.center) - radius - other.radius;
}