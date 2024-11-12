#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;

// Constructor por defecto, inicializa la raíz como nula
template<class T>
Arbol<T>::Arbol()
{
    this->raiz = nullptr;
}

// Constructor que inicializa la raíz con un valor dado
template<class T>
Arbol<T>::Arbol(T val)
{
    this->raiz = new Nodo<T>(val); // Crea un nuevo nodo con el valor dado
}

// Verifica si el árbol está vacío
template<class T>
bool Arbol<T>::esVacio()
{
    return (this->raiz == nullptr); // Retorna true si la raíz es nula
}

// Obtiene el dato almacenado en la raíz del árbol
template<class T>
T Arbol<T>::obtenerRaiz()
{
    return this->raiz->obtenerDato(); // Retorna el dato del nodo raíz
}

// Fija un nuevo nodo como la raíz del árbol
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root; // Asigna el nodo root como la nueva raíz
}

// Retorna la altura del árbol
template<class T>
int Arbol<T>::altura()
{
    return this->raiz->altura(); // Llama al método altura del nodo raíz
}

// Retorna el tamaño del árbol (número de nodos)
template<class T>
int Arbol<T>::tamano()
{
    return this->raiz->tamano(); // Llama al método tamaño del nodo raíz
}

// Inserta un nuevo nodo como hijo del nodo con valor 'padre'
template<class T>
bool Arbol<T>::insertarNodo(T padre, T val)
{
    Nodo<T>* aux = this->raiz->buscar(padre); // Busca el nodo padre
    if (aux == nullptr)
        return false; // Si no se encuentra el nodo padre, retorna false
    aux->adicionarDesc(val); // Agrega el nuevo valor como hijo
    return true;
}

// Elimina un nodo con el valor especificado
template<class T>
bool Arbol<T>::eliminar(T& val)
{
    return this->raiz->eliminarDesc(val); // Llama al método eliminar del nodo raíz
}

// Busca un nodo con el valor especificado
template<class T>
Nodo<T>* Arbol<T>::buscar(T val)
{
    return this->raiz->buscar(val); // Llama al método buscar del nodo raíz
}

// Recorre el árbol en preorden
template<class T>
void Arbol<T>::preOrden()
{
    if (this->raiz)
        this->raiz->preOrden(); // Llama al método preOrden del nodo raíz
}

// Recorre el árbol en inorden
template<class T>
void Arbol<T>::inOrden()
{
    if (this->raiz)
        this->raiz->inOrden(); // Llama al método inOrden del nodo raíz
}

// Recorre el árbol en postorden
template<class T>
void Arbol<T>::posOrden()
{
    if (this->raiz)
        this->raiz->posOrden(); // Llama al método posOrden del nodo raíz
}

// Recorre el árbol por niveles
template<class T>
void Arbol<T>::nivelOrden()
{
    if (this->raiz)
        this->raiz->nivelOrden(); // Llama al método nivelOrden del nodo raíz
}
