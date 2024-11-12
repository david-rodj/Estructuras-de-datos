#include "Punto.h"
#include <cmath>

Punto &Punto::operator=(const Punto &p)
{
    if (this != &p)
    { // Evitar la auto-asignación
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

bool Punto::operator==(const Punto &p) const
{
    return (this->x == p.x) && (this->y == p.y);
}

std::ostream &operator<<(std::ostream &o, const Punto &p)
{
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}

int Punto::distanciaEuclidiana(Punto val2)
{
    return sqrt(pow(this->x - val2.x, 2) + pow(this->y - val2.y, 2));
}
