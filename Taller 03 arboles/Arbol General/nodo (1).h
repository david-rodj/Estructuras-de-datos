#ifndef __NODO__H__
#define __NODO__H__

#include <vector>

// Clase genérica para representar un nodo de árbol
template<class T>
class Nodo {
protected:
    T dato; // Dato almacenado en el nodo
    std::vector<Nodo<T>*> hijos; // Vector de punteros a los nodos hijos

public:
    // Constructor por defecto
    Nodo();

    // Constructor que inicializa el nodo con un valor
    Nodo(T valor);

    // Retorna la altura del nodo
    int altura();

    // Retorna el tamaño del subárbol con este nodo como raíz
    int tamano();

    // Obtiene el dato almacenado en el nodo
    T& obtenerDato();

    // Fija un nuevo valor al nodo
    void fijarDato(T& val);

    // Elimina todos los nodos hijos y el nodo actual
    void limpiarLista();

    // Agrega un nuevo nodo hijo con el valor especificado
    void adicionarDesc(T& val);

    // Elimina un nodo hijo con el valor especificado
    bool eliminarDesc(T& val);

    // Recorre el subárbol en preorden
    void preOrden();

    // Recorre el subárbol en postorden
    void posOrden();

    // Recorre el subárbol por niveles
    void nivelOrden();

    // Busca un nodo con el valor especificado en el subárbol
    Nodo* buscar(T val);
};

#include "nodo.hxx" // Implementación de los métodos
#endif
