#include <iostream>
#include <queue> // Incluye la biblioteca queue para el recorrido por niveles
#include "nodo.h"

using namespace std;

// Constructor por defecto
template<class T>
Nodo<T>::Nodo()
{
}

// Constructor que inicializa el nodo con un valor
template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor; // Asigna el valor al nodo
}

// Obtiene el dato almacenado en el nodo
template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato; // Retorna una referencia al dato
}

// Fija un nuevo valor al nodo
template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val; // Asigna el nuevo valor al nodo
}

// Retorna la altura del subárbol con este nodo como raíz
template<class T>
int Nodo<T>::altura()
{
    if (hijos.size() == 0)
        return 0; // Si no hay hijos, la altura es 0

    int maximo = 0, aux_altura;
    for (size_t i = 0; i < hijos.size(); i++) {
        aux_altura = hijos[i]->altura(); // Calcula la altura de cada hijo
        if (aux_altura > maximo)
            maximo = aux_altura; // Encuentra la máxima altura entre los hijos
    }
    return maximo + 1; // Suma 1 para incluir el nodo actual
}

// Retorna el tamaño del subárbol con este nodo como raíz
template<class T>
int Nodo<T>::tamano()
{
    int conta = 1; // Incluye el nodo actual
    for (size_t i = 0; i < hijos.size(); ++i) {
        conta += hijos[i]->tamano(); // Suma el tamaño de cada subárbol hijo
    }
    return conta;
}

// Elimina todos los nodos hijos y el nodo actual
template<class T>
void Nodo<T>::limpiarLista()
{
    for (size_t i = 0; i < hijos.size(); ++i) {
        hijos[i]->limpiarLista(); // Llama recursivamente a limpiarLista en cada hijo
    }
    delete this; // Elimina el nodo actual
}

// Agrega un nuevo nodo hijo con el valor especificado
template<class T>
void Nodo<T>::adicionarDesc(T &val)
{
    Nodo<T>* hijo = new Nodo<T>(val); // Crea un nuevo nodo con el valor especificado
    hijos.push_back(hijo); // Agrega el nuevo nodo al vector de hijos
}

// Elimina un nodo hijo con el valor especificado
template<class T>
bool Nodo<T>::eliminarDesc(T &val)
{
    for (size_t i = 0; i < hijos.size(); i++) {
        if (hijos[i]->obtenerDato() == val) {
            delete hijos[i]; // Elimina el nodo hijo
            hijos.erase(hijos.begin() + i); // Elimina el puntero del vector
            return true;
        }
    }
    return false; // Retorna false si no se encontró el nodo hijo
}

// Busca un nodo con el valor especificado en el subárbol
template<class T>
Nodo<T>* Nodo<T>::buscar(T val)
{
    if (this->dato == val)
        return this; // Retorna el nodo si el valor coincide

    for (size_t i = 0; i < hijos.size(); i++) {
        Nodo<T>* aux = hijos[i]->buscar(val); // Busca recursivamente en los hijos
        if (aux != nullptr)
            return aux; // Retorna el nodo si se encuentra
    }

    return nullptr; // Retorna nullptr si no se encuentra el valor
}

// Recorre el subárbol en preorden
template<class T>
void Nodo<T>::preOrden()
{
    cout << "\t" << this->obtenerDato() << endl; // Imprime el dato del nodo actual
    for (size_t i = 0; i < hijos.size(); i++) {
        hijos[i]->preOrden(); // Llama recursivamente a preOrden en cada hijo
    }
}

// Recorre el subárbol en postorden
template<class T>
void Nodo<T>::posOrden()
{
    for (size_t i = 0; i < hijos.size(); i++) {
        hijos[i]->posOrden(); // Llama recursivamente a posOrden en cada hijo
    }
    cout << "\t" << this->obtenerDato() << endl; // Imprime el dato del nodo actual
}

// Recorre el subárbol por niveles
template<class T>
void Nodo<T>::nivelOrden()
{
    queue<Nodo<T>*> cola; // Cola para el recorrido por niveles
    cola.push(this); // Agrega el nodo actual a la cola
    while (!cola.empty()) {
        Nodo<T>* actual = cola.front(); // Toma el nodo del frente de la cola
        cola.pop(); // Remueve el nodo de la cola
        cout << "\t" << actual->obtenerDato() << endl; // Imprime el dato del nodo
        for (size_t i = 0; i < actual->hijos.size(); i++) {
            cola.push(actual->hijos[i]); // Agrega los hijos del nodo actual a la cola
        }
    }
}
