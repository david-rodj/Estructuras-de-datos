#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

class Palabra {
private:
    std::string palabra;
    unsigned int n_linea;

public:
    Palabra() : palabra(""), n_linea(0) {}
    Palabra(const std::string& n_palabra, unsigned int n_num)
        : palabra(n_palabra), n_linea(n_num) {}

    void FijarPalabra(const std::string& n_palabra) {
        palabra = n_palabra;
    }

    void FijarNumLinea(unsigned int n_num) {
        n_linea = n_num;
    }

    std::string ObtenerPalabra() const {
        return palabra;
    }

    unsigned int ObtenerNumLinea() const {
        return n_linea;
    }
};

class ArchivoTexto {
private:
    std::vector<std::list<Palabra>> lineasTexto;

public:
    ArchivoTexto() {}

    void FijarListaLineas(const std::vector<std::list<Palabra>>& n_lista) {
        lineasTexto = n_lista;
    }

    std::vector<std::list<Palabra>> ObtenerListaLineas() const {
        return lineasTexto;
    }

    size_t ObtenerNumLineas() const {
        return lineasTexto.size();
    }

    void AgregarListaPals(const std::list<Palabra>& n_lista) {
        lineasTexto.push_back(n_lista);
    }

    std::list<Palabra> BuscarPrincipio(const std::string& subcadena) const {
        std::list<Palabra> resultados;

        for (std::vector<std::list<Palabra>>::const_iterator linea_it = lineasTexto.begin(); linea_it != lineasTexto.end(); ++linea_it) {
            for (std::list<Palabra>::const_iterator palabra_it = linea_it->begin(); palabra_it != linea_it->end(); ++palabra_it) {
                if (palabra_it->ObtenerPalabra().find(subcadena) == 0) {
                    resultados.push_back(*palabra_it);
                }
            }
        }

        return resultados;
    }

    std::list<Palabra> BuscarContiene(const std::string& subcadena) const {
        std::list<Palabra> resultados;

        for (std::vector<std::list<Palabra>>::const_iterator linea_it = lineasTexto.begin(); linea_it != lineasTexto.end(); ++linea_it) {
            for (std::list<Palabra>::const_iterator palabra_it = linea_it->begin(); palabra_it != linea_it->end(); ++palabra_it) {
                if (palabra_it->ObtenerPalabra().find(subcadena) != std::string::npos) {
                    resultados.push_back(*palabra_it);
                }
            }
        }

        return resultados;
    }
};

#endif // CLASES_H