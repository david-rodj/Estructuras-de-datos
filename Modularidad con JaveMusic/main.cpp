#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>

#include "JaveMusic.h"

void LeerCancionesDesdeArchivo(JaveMusic& javeMusic, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    int numCanciones;
    archivo >> numCanciones;
    archivo.ignore();

    for (int i = 0; i < numCanciones; ++i) {
        std::string linea;
        if (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string nombreCancion, nombreArtista, genero, nombreAlbum, añoStr;

            if (std::getline(ss, nombreCancion, '|') &&
                std::getline(ss, nombreArtista, '|') &&
                std::getline(ss, genero, '|') &&
                std::getline(ss, nombreAlbum, '|') &&
                std::getline(ss, añoStr)) {

                int año = std::stoi(añoStr);

                Cancion cancion(nombreCancion);

                auto& artistas = javeMusic.ObtenerArtistas();
                auto itArtista = std::find_if(artistas.begin(), artistas.end(), 
                                              [&nombreArtista](const Artista& artista) {
                                                  return artista.ObtenerNombre() == nombreArtista;
                                              });

                if (itArtista == artistas.end()) {
                  artistas.push_back(Artista(nombreArtista));  
                  itArtista = --artistas.end();  
                }

                auto& albumes = itArtista->ObtenerAlbumes();
                auto itAlbum = std::find_if(albumes.begin(), albumes.end(), 
                                            [&nombreAlbum, año](const Album& album) {
                                                return album.ObtenerNombre() == nombreAlbum && album.ObtenerAnio() == año;
                                            });

                if (itAlbum == albumes.end()) {
                  albumes.push_back(Album(nombreAlbum, año));  
                  itAlbum = --albumes.end();  
                }

                itAlbum->AgregarCancion(cancion);
            }
        }
    }

    archivo.close();
}

void ListarAutores(const JaveMusic& javeMusic) {
    std::cout<<std::endl;
    std::deque<std::string> autores;
    const auto& artistas = javeMusic.ObtenerArtistas();
    for (auto it = artistas.cbegin(); it != artistas.cend(); ++it) {
        autores.push_back(it->ObtenerNombre());
    }
    std::sort(autores.begin(), autores.end());
    std::cout << "Autores:\n\n";
    for (auto it = autores.cbegin(); it != autores.cend(); ++it) {
        std::cout << "- "<<*it << std::endl;
    }
}


void ListarCancionesPorAutor(const JaveMusic& javeMusic, const std::string& nombreArtista) {
    std::cout<<std::endl;
    const auto& artistas = javeMusic.ObtenerArtistas();
    auto itArtista = std::find_if(artistas.cbegin(), artistas.cend(),
                                  [&nombreArtista](const Artista& artista) {
                                      return artista.ObtenerNombre() == nombreArtista;
                                  });

    if (itArtista != artistas.cend()) {
        std::deque<std::string> canciones;
        const auto& albumes = itArtista->ObtenerAlbumes();
        for (auto itAlbum = albumes.cbegin(); itAlbum != albumes.cend(); ++itAlbum) {
            const auto& cancionesAlbum = itAlbum->ObtenerCanciones();
            for (auto itCancion = cancionesAlbum.cbegin(); itCancion != cancionesAlbum.cend(); ++itCancion) {
                canciones.push_back(itCancion->ObtenerNombre());
            }
        }
        std::sort(canciones.begin(), canciones.end());
        std::cout << "Canciones de " << nombreArtista << ":\n\n";
        for (auto it = canciones.cbegin(); it != canciones.cend(); ++it) {
            std::cout << "- "<< *it << std::endl;
        }
    } else {
        std::cout << "Artista no encontrado.\n\n" << std::endl;
    }
}


void ListarAlbumes(const JaveMusic& javeMusic) {
    std::cout<<std::endl;
    std::deque<Album> albumes;
    const auto& artistas = javeMusic.ObtenerArtistas();
    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        const auto& albumesArtista = itArtista->ObtenerAlbumes();
        for (auto itAlbum = albumesArtista.cbegin(); itAlbum != albumesArtista.cend(); ++itAlbum) {
            albumes.push_back(*itAlbum);
        }
    }
    std::sort(albumes.begin(), albumes.end(),
              [](const Album& a, const Album& b) {
                  return a.ObtenerAnio() < b.ObtenerAnio();
              });
    std::cout << "Álbumes:\n\n";
    for (auto it = albumes.cbegin(); it != albumes.cend(); ++it) {
        std::cout << it->ObtenerNombre() << " (" << it->ObtenerAnio() << ")" << std::endl;
    }
}


void ListarCancionesPorAlbum(const JaveMusic& javeMusic, const std::string& nombreAlbum) {
    std::cout<<std::endl;
    const auto& artistas = javeMusic.ObtenerArtistas();
    std::deque<Album>::const_iterator itAlbum; 
    bool albumEncontrado = false;

    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        const auto& albumes = itArtista->ObtenerAlbumes();
        itAlbum = std::find_if(albumes.cbegin(), albumes.cend(),
                               [&nombreAlbum](const Album& album) {
                                   return album.ObtenerNombre() == nombreAlbum;
                               });

        if (itAlbum != albumes.cend()){
            albumEncontrado = true;
            std::deque<std::string> canciones;
            const auto& cancionesAlbum = itAlbum->ObtenerCanciones();
            for (auto itCancion = cancionesAlbum.cbegin(); itCancion != cancionesAlbum.cend(); ++itCancion) 
                canciones.push_back(itCancion->ObtenerNombre());
            
            std::sort(canciones.begin(), canciones.end());
            std::cout << "Canciones del álbum " << nombreAlbum <<"\n\n";
            for (auto it = canciones.cbegin(); it != canciones.cend(); ++it) {
                std::cout << "- " << *it << std::endl;
            }
            break; 
        }
    }
  
    if (!albumEncontrado) {
        std::cout << "Álbum no encontrado.\n\n" << std::endl;
    }
}


void ListarCancionesOrdenadas(const JaveMusic& javeMusic) {
    std::deque<Album> albumesOrdenados;

    const auto& artistas = javeMusic.ObtenerArtistas();
    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        const auto& albumes = itArtista->ObtenerAlbumes();
        for (auto itAlbum = albumes.cbegin(); itAlbum != albumes.cend(); ++itAlbum) {
            albumesOrdenados.push_back(*itAlbum);
        }
    }

    std::sort(albumesOrdenados.begin(), albumesOrdenados.end(),
              [](const Album& a, const Album& b) {
                  return a.ObtenerNombre() < b.ObtenerNombre();
              });

    for (auto itAlbum = albumesOrdenados.cbegin(); itAlbum != albumesOrdenados.cend(); ++itAlbum) {
        std::deque<Cancion> cancionesOrdenadas = itAlbum->ObtenerCanciones();
        std::sort(cancionesOrdenadas.begin(), cancionesOrdenadas.end(),
                  [](const Cancion& a, const Cancion& b) {
                      return a.ObtenerNombre() < b.ObtenerNombre();
                  });

      std::cout << "\nÁlbum: " << itAlbum->ObtenerNombre() << "\n\n";
        for (auto itCancion = cancionesOrdenadas.cbegin(); itCancion != cancionesOrdenadas.cend(); ++itCancion) {
            std::cout << "- Canción: " << itCancion->ObtenerNombre() << std::endl;
        }
    }
}


int main(int argc, char* argv[]) {
  if (argc < 2) {
      std::cout << "No se dio un archivo para leer"<<std::endl;
      return 1;
  }

  std::string nombreArchivo = argv[1];
  JaveMusic javeMusic;

  LeerCancionesDesdeArchivo(javeMusic, nombreArchivo);

  int opcion;
  while (true) {
      std::cout << "\nMenú:\n\n";
      std::cout << "1. Listar todos los autores\n";
      std::cout << "2. Listar canciones de un autor\n";
      std::cout << "3. Listar todos los álbumes\n";
      std::cout << "4. Listar canciones de un álbum\n";
      std::cout << "5. Listar todas las canciones ordenadas\n";
      std::cout << "6. Salir\n\n";
      std::cout << "Elige una opción: ";
      std::cin >> opcion;

      switch (opcion) {
          case 1:
              ListarAutores(javeMusic);
              break;
          case 2: {
              std::cout<<std::endl;
              std::string nombreArtista;
              std::cout << "Ingresa el nombre del autor: ";
              std::cin.ignore();
              std::getline(std::cin, nombreArtista);
              ListarCancionesPorAutor(javeMusic, nombreArtista);
              break;
          }
          case 3:
              ListarAlbumes(javeMusic);
              break;
          case 4: {
              std::cout<<std::endl;
              std::string nombreAlbum;
              int año;
              std::cout << "Ingresa el nombre del álbum: ";
              std::cin.ignore();
              std::getline(std::cin, nombreAlbum);
              ListarCancionesPorAlbum(javeMusic, nombreAlbum);
              break;
          }
          case 5:
              ListarCancionesOrdenadas(javeMusic);
              break;
          case 6:
              return 0;
          default:
              std::cout << "\nOpción no válida. Inténtalo de nuevo.\n\n" << std::endl;
      }
  }

  return 0;
}
