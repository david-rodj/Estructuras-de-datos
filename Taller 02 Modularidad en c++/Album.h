#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <deque>
#include "Cancion.h"

class Album {
private:
    std::string nombre;
    int anio;
    std::deque<Cancion> canciones;

public:
    Album(const std::string& nombre, int anio)
        : nombre(nombre), anio(anio) {}

    void FijarNombre(const std::string& nombre) { this->nombre = nombre; }
    void FijarAnio(int anio) { this->anio = anio; }
    void AgregarCancion(const Cancion& cancion) { canciones.push_back(cancion); }

    std::string ObtenerNombre() const { return nombre; }
    int ObtenerAnio() const { return anio; }
    std::deque<Cancion>& ObtenerCanciones() { return canciones; }
    const std::deque<Cancion>& ObtenerCanciones() const { return canciones; }
};

#endif
