#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <algorithm>

#include "JaveMusic.h"

// Función para leer canciones desde un archivo y agregarlas a la colección de JaveMusic.
void LeerCancionesDesdeArchivo(JaveMusic& javeMusic, const std::string& nombreArchivo) {
    // Abre el archivo con el nombre especificado para lectura.
    std::ifstream archivo(nombreArchivo);
    
    // Verifica si el archivo se abrió correctamente.
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return; // Sale de la función si no se pudo abrir el archivo.
    }

    int numCanciones;
    archivo >> numCanciones; // Lee el número total de canciones en el archivo.
    archivo.ignore(); // Ignora el carácter de nueva línea después del número de canciones.

    // Procesa cada línea del archivo, que representa una canción.
    for (int i = 0; i < numCanciones; ++i) {
        std::string linea;
        
        // Lee una línea del archivo que contiene los datos de una canción.
        if (std::getline(archivo, linea)) {
            std::istringstream ss(linea); // Usa un stringstream para analizar la línea.
            std::string nombreCancion, nombreArtista, genero, nombreAlbum, añoStr;

            // Extrae los datos de la línea usando el delimitador '|'.
            if (std::getline(ss, nombreCancion, '|') &&
                std::getline(ss, nombreArtista, '|') &&
                std::getline(ss, genero, '|') &&
                std::getline(ss, nombreAlbum, '|') &&
                std::getline(ss, añoStr)) {

                int año = std::stoi(añoStr); // Convierte el año de string a entero.

                Cancion cancion(nombreCancion); // Crea un objeto Cancion con el nombre leído.

                // Obtiene la lista de artistas desde el objeto JaveMusic.
                auto& artistas = javeMusic.ObtenerArtistas();
                // Busca el artista en la lista de artistas.
                auto itArtista = std::find_if(artistas.begin(), artistas.end(), 
                                              [&nombreArtista](const Artista& artista) {
                                                  return artista.ObtenerNombre() == nombreArtista;
                                              });

                // Si el artista no está en la lista, lo agrega.
                if (itArtista == artistas.end()) {
                    artistas.push_back(Artista(nombreArtista));  
                    itArtista = --artistas.end();  // Obtiene el iterador del nuevo artista agregado.
                }

                // Obtiene la lista de álbumes del artista encontrado.
                auto& albumes = itArtista->ObtenerAlbumes();
                // Busca el álbum en la lista de álbumes del artista.
                auto itAlbum = std::find_if(albumes.begin(), albumes.end(), 
                                            [&nombreAlbum, año](const Album& album) {
                                                return album.ObtenerNombre() == nombreAlbum && album.ObtenerAnio() == año;
                                            });

                // Si el álbum no está en la lista, lo agrega.
                if (itAlbum == albumes.end()) {
                    albumes.push_back(Album(nombreAlbum, año));  
                    itAlbum = --albumes.end();  // Obtiene el iterador del nuevo álbum agregado.
                }

                // Agrega la canción al álbum correspondiente.
                itAlbum->AgregarCancion(cancion);
            }
        }
    }

    archivo.close(); // Cierra el archivo después de terminar la lectura.
}

// Función para listar los autores (artistas) en JaveMusic.
void ListarAutores(const JaveMusic& javeMusic) {
    std::cout << std::endl; // Imprime una línea en blanco para separar la salida.
    
    std::deque<std::string> autores; // Declara una deque para almacenar los nombres de los autores.
    
    // Obtiene la lista de artistas desde el objeto JaveMusic.
    const auto& artistas = javeMusic.ObtenerArtistas();
    
    // Recorre la lista de artistas y agrega sus nombres a la deque de autores.
    for (auto it = artistas.cbegin(); it != artistas.cend(); ++it) {
        autores.push_back(it->ObtenerNombre());
    }
    
    // Ordena la deque de autores alfabéticamente.
    std::sort(autores.begin(), autores.end());
    
    std::cout << "Autores:\n\n"; // Imprime el encabezado para la lista de autores.
    
    // Imprime la lista de autores.
    for (auto it = autores.cbegin(); it != autores.cend(); ++it) {
        std::cout << "- " << *it << std::endl;
    }
}

// Función para listar las canciones de un autor específico en JaveMusic.
void ListarCancionesPorAutor(const JaveMusic& javeMusic, const std::string& nombreArtista) {
    std::cout << std::endl; // Imprime una línea en blanco para separar la salida.

    // Obtiene la lista de artistas desde el objeto JaveMusic.
    const auto& artistas = javeMusic.ObtenerArtistas();
    
    // Busca el artista cuyo nombre coincide con nombreArtista.
    auto itArtista = std::find_if(artistas.cbegin(), artistas.cend(),
                                  [&nombreArtista](const Artista& artista) {
                                      return artista.ObtenerNombre() == nombreArtista;
                                  });

    // Verifica si el artista fue encontrado.
    if (itArtista != artistas.cend()) {
        std::deque<std::string> canciones; // Declara una deque para almacenar los nombres de las canciones.
        
        // Obtiene la lista de álbumes del artista encontrado.
        const auto& albumes = itArtista->ObtenerAlbumes();
        
        // Recorre los álbumes del artista.
        for (auto itAlbum = albumes.cbegin(); itAlbum != albumes.cend(); ++itAlbum) {
            // Obtiene la lista de canciones de cada álbum.
            const auto& cancionesAlbum = itAlbum->ObtenerCanciones();
            
            // Recorre las canciones del álbum y las agrega a la deque de canciones.
            for (auto itCancion = cancionesAlbum.cbegin(); itCancion != cancionesAlbum.cend(); ++itCancion) {
                canciones.push_back(itCancion->ObtenerNombre());
            }
        }
        
        // Ordena la deque de canciones alfabéticamente.
        std::sort(canciones.begin(), canciones.end());
        
        // Imprime el encabezado para la lista de canciones del autor.
        std::cout << "Canciones de " << nombreArtista << ":\n\n";
        
        // Imprime la lista de canciones del autor.
        for (auto it = canciones.cbegin(); it != canciones.cend(); ++it) {
            std::cout << "- " << *it << std::endl;
        }
    } else {
        // Imprime un mensaje si el artista no fue encontrado.
        std::cout << "Artista no encontrado.\n\n" << std::endl;
    }
}

// Función para listar todos los álbumes en JaveMusic ordenados por año.
void ListarAlbumes(const JaveMusic& javeMusic) {
    std::cout << std::endl; // Imprime una línea en blanco para separar la salida.

    std::deque<Album> albumes; // Declara una deque para almacenar todos los álbumes.

    // Obtiene la lista de artistas desde el objeto JaveMusic.
    const auto& artistas = javeMusic.ObtenerArtistas();

    // Recorre la lista de artistas.
    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        // Obtiene la lista de álbumes del artista actual.
        const auto& albumesArtista = itArtista->ObtenerAlbumes();

        // Recorre los álbumes del artista y los agrega a la deque de álbumes.
        for (auto itAlbum = albumesArtista.cbegin(); itAlbum != albumesArtista.cend(); ++itAlbum) {
            albumes.push_back(*itAlbum);
        }
    }

    // Ordena la deque de álbumes por año de lanzamiento de forma ascendente.
    std::sort(albumes.begin(), albumes.end(),
              [](const Album& a, const Album& b) {
                  return a.ObtenerAnio() < b.ObtenerAnio();
              });

    // Imprime el encabezado para la lista de álbumes.
    std::cout << "Álbumes:\n\n";

    // Imprime la lista de álbumes ordenados por año.
    for (auto it = albumes.cbegin(); it != albumes.cend(); ++it) {
        std::cout << it->ObtenerNombre() << " (" << it->ObtenerAnio() << ")" << std::endl;
    }
}

// Función para listar todas las canciones de un álbum específico en JaveMusic.
void ListarCancionesPorAlbum(const JaveMusic& javeMusic, const std::string& nombreAlbum) {
    std::cout << std::endl; // Imprime una línea en blanco para separar la salida.

    // Obtiene la lista de artistas desde el objeto JaveMusic.
    const auto& artistas = javeMusic.ObtenerArtistas();

    // Declara un iterador para álbumes y una bandera para verificar si el álbum fue encontrado.
    std::deque<Album>::const_iterator itAlbum; 
    bool albumEncontrado = false;

    // Recorre la lista de artistas.
    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        // Obtiene la lista de álbumes del artista actual.
        const auto& albumes = itArtista->ObtenerAlbumes();

        // Busca el álbum con el nombre especificado en la lista de álbumes del artista.
        itAlbum = std::find_if(albumes.cbegin(), albumes.cend(),
                               [&nombreAlbum](const Album& album) {
                                   return album.ObtenerNombre() == nombreAlbum;
                               });

        // Si se encuentra el álbum, procesa sus canciones.
        if (itAlbum != albumes.cend()) {
            albumEncontrado = true; // Marca el álbum como encontrado.
            std::deque<std::string> canciones; // Declara una deque para almacenar los nombres de las canciones.

            // Obtiene la lista de canciones del álbum encontrado.
            const auto& cancionesAlbum = itAlbum->ObtenerCanciones();

            // Recorre las canciones del álbum y las agrega a la deque de canciones.
            for (auto itCancion = cancionesAlbum.cbegin(); itCancion != cancionesAlbum.cend(); ++itCancion) 
                canciones.push_back(itCancion->ObtenerNombre());
            
            // Ordena la deque de canciones alfabéticamente.
            std::sort(canciones.begin(), canciones.end());

            // Imprime el encabezado para la lista de canciones del álbum.
            std::cout << "Canciones del álbum " << nombreAlbum << "\n\n";

            // Imprime la lista de canciones ordenadas.
            for (auto it = canciones.cbegin(); it != canciones.cend(); ++it) {
                std::cout << "- " << *it << std::endl;
            }
            break; // Sale del bucle ya que se encontró y procesó el álbum.
        }
    }
  
    // Si el álbum no fue encontrado, imprime un mensaje de error.
    if (!albumEncontrado) {
        std::cout << "Álbum no encontrado.\n\n" << std::endl;
    }
}

// Función para listar todas las canciones de todos los álbumes en JaveMusic, ordenadas por nombre de álbum y canción.
void ListarCancionesOrdenadas(const JaveMusic& javeMusic) {
    // Declara una deque para almacenar los álbumes ordenados.
    std::deque<Album> albumesOrdenados;

    // Obtiene la lista de artistas desde el objeto JaveMusic.
    const auto& artistas = javeMusic.ObtenerArtistas();

    // Recorre la lista de artistas.
    for (auto itArtista = artistas.cbegin(); itArtista != artistas.cend(); ++itArtista) {
        // Obtiene la lista de álbumes del artista actual.
        const auto& albumes = itArtista->ObtenerAlbumes();

        // Recorre los álbumes del artista y los agrega a la deque de álbumes ordenados.
        for (auto itAlbum = albumes.cbegin(); itAlbum != albumes.cend(); ++itAlbum) {
            albumesOrdenados.push_back(*itAlbum);
        }
    }

    // Ordena la deque de álbumes alfabéticamente por el nombre del álbum.
    std::sort(albumesOrdenados.begin(), albumesOrdenados.end(),
              [](const Album& a, const Album& b) {
                  return a.ObtenerNombre() < b.ObtenerNombre();
              });

    // Recorre los álbumes ordenados.
    for (auto itAlbum = albumesOrdenados.cbegin(); itAlbum != albumesOrdenados.cend(); ++itAlbum) {
        // Declara una deque para almacenar las canciones ordenadas del álbum actual.
        std::deque<Cancion> cancionesOrdenadas = itAlbum->ObtenerCanciones();

        // Ordena la deque de canciones alfabéticamente por el nombre de la canción.
        std::sort(cancionesOrdenadas.begin(), cancionesOrdenadas.end(),
                  [](const Cancion& a, const Cancion& b) {
                      return a.ObtenerNombre() < b.ObtenerNombre();
                  });

        // Imprime el nombre del álbum.
        std::cout << "\nÁlbum: " << itAlbum->ObtenerNombre() << "\n\n";

        // Recorre las canciones ordenadas del álbum e imprime su nombre.
        for (auto itCancion = cancionesOrdenadas.cbegin(); itCancion != cancionesOrdenadas.cend(); ++itCancion) {
            std::cout << "- Canción: " << itCancion->ObtenerNombre() << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    // Verifica si se ha pasado al menos un argumento (el nombre del archivo) al ejecutar el programa.
    if (argc < 2) {
        std::cout << "No se dio un archivo para leer" << std::endl;
        return 1; // Retorna un código de error si no se ha proporcionado el archivo.
    }

    // Obtiene el nombre del archivo desde el argumento de la línea de comandos.
    std::string nombreArchivo = argv[1];
    JaveMusic javeMusic; // Crea una instancia del objeto JaveMusic.

    // Llama a la función para leer canciones desde el archivo.
    LeerCancionesDesdeArchivo(javeMusic, nombreArchivo);

    int opcion; // Variable para almacenar la opción seleccionada por el usuario.

    while (true) {
        // Muestra el menú de opciones al usuario.
        std::cout << "\nMenú:\n\n";
        std::cout << "1. Listar todos los autores\n";
        std::cout << "2. Listar canciones de un autor\n";
        std::cout << "3. Listar todos los álbumes\n";
        std::cout << "4. Listar canciones de un álbum\n";
        std::cout << "5. Listar todas las canciones ordenadas\n";
        std::cout << "6. Salir\n\n";
        std::cout << "Elige una opción: ";
        std::cin >> opcion; // Lee la opción del usuario.

        // Ejecuta la acción correspondiente según la opción seleccionada.
        switch (opcion) {
            case 1:
                // Lista todos los autores.
                ListarAutores(javeMusic);
                break;
            case 2: {
                // Lista canciones de un autor específico.
                std::cout << std::endl;
                std::string nombreArtista;
                std::cout << "Ingresa el nombre del autor: ";
                std::cin.ignore(); // Limpia el buffer de entrada.
                std::getline(std::cin, nombreArtista); // Lee el nombre del autor.
                ListarCancionesPorAutor(javeMusic, nombreArtista);
                break;
            }
            case 3:
                // Lista todos los álbumes.
                ListarAlbumes(javeMusic);
                break;
            case 4: {
                // Lista canciones de un álbum específico.
                std::cout << std::endl;
                std::string nombreAlbum;
                std::cout << "Ingresa el nombre del álbum: ";
                std::cin.ignore(); // Limpia el buffer de entrada.
                std::getline(std::cin, nombreAlbum); // Lee el nombre del álbum.
                ListarCancionesPorAlbum(javeMusic, nombreAlbum);
                break;
            }
            case 5:
                // Lista todas las canciones ordenadas por nombre de álbum y canción.
                ListarCancionesOrdenadas(javeMusic);
                break;
            case 6:
                // Sale del programa.
                return 0;
            default:
                // Mensaje para opción no válida.
                std::cout << "\nOpción no válida. Inténtalo de nuevo.\n\n" << std::endl;
        }
    }

    return 0; // Retorna 0 al finalizar el programa exitosamente.
}

