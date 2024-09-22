#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
#include <deque>
#include "Album.h"

class Artista {
private:
    std::string nombre;
    std::deque<Album> albumes;

public:
    Artista(const std::string& nombre) : nombre(nombre) {}

    void FijarNombre(const std::string& nombre) { this->nombre = nombre; }
    void AgregarAlbum(const Album& album) { albumes.push_back(album); }

    std::string ObtenerNombre() const { return nombre; }
    std::deque<Album>& ObtenerAlbumes() { return albumes; }
    const std::deque<Album>& ObtenerAlbumes() const { return albumes; }
};

#endif
