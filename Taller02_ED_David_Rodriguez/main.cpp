/********************************************************
Pontificia Universidad Javeriana
Autor: David rodriguez
Fecha: 19/08/2024
Materia: Estructuras de datos
Tema: Taller 02
********************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include "Clases.h"

std::vector<std::list<Palabra>> LeerArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::vector<std::list<Palabra>> vectorLineas;
    std::string palabra;
    int numLineas = 0;

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        exit(1);
    }

    archivo >> numLineas;
    archivo.ignore(); 

    vectorLineas.resize(numLineas);

    int lineaActual = 1;
    while ((lineaActual <= numLineas) && (std::getline(archivo, palabra))){
        std::istringstream ss(palabra);
        while (ss >> palabra) {
            Palabra p(palabra, lineaActual);
            vectorLineas[lineaActual - 1].push_back(p);
        }
        ++lineaActual;
    }

    archivo.close();
    return vectorLineas;
}

std::string InvertirCadena(const std::string& cadena) {
    std::string invertida = cadena;
    std::reverse(invertida.begin(), invertida.end());
    return invertida;
}

int main(int argc, char* argv[]) {
    if (argc < 2) 
        exit(1);

    std::string nombreArchivo = argv[1];
    std::vector<std::list<Palabra>> vectorLineas = LeerArchivo(nombreArchivo);
    ArchivoTexto archivoTexto;
    archivoTexto.FijarListaLineas(vectorLineas);

    std::string subcadena;
    std::cout << "Ingresa una subcadena: ";
    std::cin >> subcadena;

    std::list<Palabra> palabrasInicio = archivoTexto.BuscarPrincipio(subcadena);
    std::list<Palabra> palabrasContiene = archivoTexto.BuscarContiene(subcadena);
    std::string subcadenaInvertida = InvertirCadena(subcadena);
    std::list<Palabra> palabrasContieneInvertida = archivoTexto.BuscarContiene(subcadenaInvertida);

    std::cout << "\nHay " << palabrasInicio.size() << " palabras que empiecen con: " << subcadena << std::endl;
    for (auto it = palabrasInicio.begin(); it != palabrasInicio.end(); ++it) {
        std::cout << "linea " << it->ObtenerNumLinea() << ": " << it->ObtenerPalabra() << std::endl;
    }

    std::cout << "\nHay " << palabrasContiene.size() << " palabras que contienen: " << subcadena << std::endl;
    for (auto it = palabrasContiene.begin(); it != palabrasContiene.end(); ++it) {
        std::cout << "linea " << it->ObtenerNumLinea() << ": " << it->ObtenerPalabra() << std::endl;
    }

    std::cout << "\nHay " << palabrasContieneInvertida.size() << " palabras que contienen: " << subcadenaInvertida << std::endl;
    for (auto it = palabrasContieneInvertida.begin(); it != palabrasContieneInvertida.end(); ++it) {
        std::cout << "linea " << it->ObtenerNumLinea() << ": " << it->ObtenerPalabra() << std::endl;
    }

    return 0;
}
