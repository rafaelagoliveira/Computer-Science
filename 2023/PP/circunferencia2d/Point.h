#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <cmath>

class Point {
private:
    float x, y;

public:
    // getters
    float getx() const;
    float gety() const;

    // setters
    void setx(float x);
    void sety(float y);

    // Metodo de calculo
    float distance(const Point &other) const;
};

#endif //POINT_H_INCLUDED