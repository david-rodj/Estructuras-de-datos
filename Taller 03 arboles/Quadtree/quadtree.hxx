#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

template<class T>
Arbol<T>::Arbol() {
    this->raiz = NULL;  // Inicializa la raíz como NULL
}

template<class T>
Arbol<T>::Arbol(pair<T,T> val) {
    this->raiz = new Nodo<T>(val);  // Crea la raíz con el valor proporcionado
}


template<class T>
bool Arbol<T>::esVacio() {
    return this->raiz == NULL;  // Devuelve true si la raíz es NULL
}

template<class T>
pair<T,T> Arbol<T>::obtenerRaiz() {
    if (this->raiz != nullptr) {
        return this->raiz->obtenerDato();  // Devuelve el valor almacenado en la raíz
    } else {
        throw runtime_error("El árbol está vacío.");  // Maneja el caso en que el árbol esté vacío
    }
}

template<class T>
int Arbol<T>::altura() {
    return (this->raiz != NULL) ? this->raiz->altura() : 0;  // Llama al método altura del nodo raíz
}

template<class T>
int Arbol<T>::tamano() {
    return (this->raiz != NULL) ? this->raiz->tamano() : 0;  // Llama al método tamaño del nodo raíz
}

template<class T>
void Arbol<T>::insertar(pair<T,T> val) {
    if (this->esVacio()) {
        // Si el árbol está vacío, crea la raíz
        this->raiz = new Nodo<T>(val);
    } else {
        // De lo contrario, inserta en el árbol existente
        this->raiz->insertar(val);
    }
}



template<class T>
Nodo<T>* Arbol<T>::buscar(pair<T,T> val) {
    return (this->raiz != NULL) ? this->raiz->buscar(val) : NULL;  // Busca en el árbol
}

template<class T>
void Arbol<T>::preOrden() {
    if (this->raiz != NULL) {
        this->raiz->preOrden();  // Realiza el recorrido en preorden
    }
}

template<class T>
void Arbol<T>::posOrden() {
    if (this->raiz != NULL) {
        this->raiz->posOrden();  // Realiza el recorrido en posorden
    }
}
