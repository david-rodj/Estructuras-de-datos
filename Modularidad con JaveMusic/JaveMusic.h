#ifndef JAVEMUSIC_H
#define JAVEMUSIC_H

#include <deque>
#include "Artista.h"

class JaveMusic {
private:
    std::deque<Artista> artistas;

public:
    void AgregarArtista(const Artista& artista) { artistas.push_back(artista); }

    std::deque<Artista>& ObtenerArtistas() { return artistas; }
    const std::deque<Artista>& ObtenerArtistas() const { return artistas; }
};

#endif
