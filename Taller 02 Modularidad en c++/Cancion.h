#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
    std::string nombre;
    double duracion; 
    int calificacion; 

public:
    Cancion(const std::string& nombre, double duracion, int calificacion)
        : nombre(nombre), duracion(duracion), calificacion(calificacion) {}

    Cancion(const std::string& nombre)
        : nombre(nombre), duracion(0.0), calificacion(0) {}

    void FijarNombre(const std::string& nombre) { this->nombre = nombre; }
    void FijarDuracion(double duracion) { this->duracion = duracion; }
    void FijarCalificacion(int calificacion) { this->calificacion = calificacion; }

    std::string ObtenerNombre() const { return nombre; }
    double ObtenerDuracion() const { return duracion; }
    int ObtenerCalificacion() const { return calificacion; }
};

#endif
