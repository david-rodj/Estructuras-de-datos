#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

// Clase genérica para representar un árbol
template<class T>
class Arbol {
protected:
    Nodo<T> *raiz; // Puntero a la raíz del árbol

public:
    // Constructor por defecto
    Arbol();

    // Constructor que inicializa la raíz con un valor
    Arbol(T val);

    // Verifica si el árbol está vacío
    bool esVacio();

    // Obtiene el valor de la raíz
    T obtenerRaiz();

    // Fija un nuevo nodo como raíz del árbol
    void fijarRaiz(Nodo<T>* root);

    // Inserta un nodo con valor 'val' como hijo de 'padre'
    bool insertarNodo(T padre, T val);

    // Retorna la altura del árbol
    int altura();

    // Retorna el tamaño del árbol (cantidad de nodos)
    int tamano();

    // Inserta un valor en el árbol
    void insertar(T& val);

    // Elimina un nodo con valor 'val'
    bool eliminar(T& val);

    // Busca un nodo con el valor especificado
    Nodo<T>* buscar(T val);

    // Recorre el árbol en preorden
    void preOrden();

    // Recorre el árbol en inorden
    void inOrden();

    // Recorre el árbol en postorden
    void posOrden();

    // Recorre el árbol por niveles
    void nivelOrden();
};

#include "arbol.hxx" // Implementación de los métodos
#endif
