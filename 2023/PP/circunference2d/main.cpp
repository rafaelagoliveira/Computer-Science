#include <iostream>
#include "Circunference.h"

int main(int, char**) {
    Circunference c1, c2;

    c1.setPosition(2, 1);
    c1.setRadius(1);
    c2.setPosition(7, 1);
    c2.setRadius(2);

    std::cout << "Distancia entre circunferencias: " << c1.distance(c2) << std::endl;

    return 0;
}
