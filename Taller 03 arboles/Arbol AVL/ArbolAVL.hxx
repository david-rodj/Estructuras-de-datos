#ifndef ARBOLAVL_HXX_INCLUDED
#define ARBOLAVL_HXX_INCLUDED

#include "ArbolAVL.h"
#include <queue>
#include <algorithm>

template < class T >
ArbolAVL<T>::ArbolAVL(){
    this->raiz = NULL;
}

template < class T >
ArbolAVL<T>::~ArbolAVL(){
    if(this-> raiz !=NULL){}
    delete this->raiz;
    this->raiz = NULL;
}

template < class T >
bool ArbolAVL<T>::esVacio(){
    return this->raiz == NULL;
}

template < class T >
T ArbolAVL<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
}

template <class T>
bool ArbolAVL<T>::insertarRaiz(NodoBinario<T>* val){
    if(val == NULL)
        return false;

    if(this->esVacio()){
        this->raiz = val;
        return true;
    }
}

//recurrente
template < class T >
int ArbolAVL<T>::altura(){
    if(this->esVacio())
        return -1;
    else
        return (this->raiz)->altura();
}

template <class T>
int ArbolAVL<T>::altura(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return -1; // Retorna -1 para un nodo nulo
    }
    return nodo->altura(); // Asumiendo que 'altura' es una variable miembro del nodo
}

//recurrente
template < class T >
int ArbolAVL<T>::tamano(){
      if (this->esVacio()) {
        return 0;
    } else {
        return (this->raiz)->tamano();
    }
}

//iterativo
template < class T >
bool ArbolAVL<T>::buscar(T val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado){
        if (val < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        } else {
            encontrado = true;
        }
    }
    return encontrado;
}

//recurrente
template < class T >
void ArbolAVL<T>::preOrden(){
     if (!this->esVacio())
        (this->raiz)->preOrden();
}

//recurrente
template < class T >
void ArbolAVL<T>::inOrden(){
    if(!this->esVacio())
        (this->raiz)->inOrden();
}

//recurrente
template < class T >
void ArbolAVL<T>::posOrden(){
    if (!this->esVacio())
        (this->raiz)->posOrden();

}

//iterativo
template < class T >
void ArbolAVL<T>::nivelOrden(){
    if (!this->esVacio()){
        std:: queue< NodoBinario<T>* > cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while (!cola.empty()){
            nodo = cola.front();
            cola.pop();
            std:: cout << nodo->obtenerDato() << " ";
            if (nodo->obtenerHijoIzq()!= NULL)
                cola.push(nodo->obtenerHijoIzq());
            if (nodo->obtenerHijoDer()!= NULL)
                cola.push(nodo->obtenerHijoDer());
        }
    }
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::obtenerSucesor(NodoBinario<T>* nodo) {
    // El sucesor está en el subárbol derecho del nodo a eliminar
    NodoBinario<T>* sucesor = nodo->obtenerHijoDer();

    // Buscar el nodo más a la izquierda en el subárbol derecho
    while (sucesor->obtenerHijoIzq() != NULL) {
        sucesor = sucesor->obtenerHijoIzq();
    }
    return sucesor;
}

template <class T>
int ArbolAVL<T>::balanceo(NodoBinario<T>* nodo) {
    if (nodo == NULL)
        return 0;
    return altura(nodo->obtenerHijoIzq()) - altura(nodo->obtenerHijoDer());
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionDerecha(NodoBinario<T>* y) {
    NodoBinario<T>* x = y->obtenerHijoIzq();
    NodoBinario<T>* T2 = x->obtenerHijoDer();

    // Realiza la rotación
    x->fijarHijoDer(y);
    y->fijarHijoIzq(T2);

    return x; // Nuevo raíz
}

// Rotación a la izquierda
template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionIzquierda(NodoBinario<T>* x) {
    NodoBinario<T>* y = x->obtenerHijoDer();
    NodoBinario<T>* T2 = y->obtenerHijoIzq();

    // Realiza la rotación
    y->fijarHijoIzq(x);
    x->fijarHijoDer(T2);

    return y; // Nuevo raíz
}

// Balancea un nodo
template <class T>
NodoBinario<T>* ArbolAVL<T>::balancear(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return nodo;
    }

    // Verifica el balanceo
    int balance = balanceo(nodo);

    // Si el nodo se desbalancea, hay 4 casos

    // Izquierda Izquierda
    if (balance > 1 && balanceo(nodo->obtenerHijoIzq()) >= 0) {
        return rotacionDerecha(nodo);
    }

    // Derecha Derecha
    if (balance < -1 && balanceo(nodo->obtenerHijoDer()) <= 0) {
        return rotacionIzquierda(nodo);
    }

    // Izquierda Derecha
    if (balance > 1 && balanceo(nodo->obtenerHijoIzq()) < 0) {
        nodo->fijarHijoIzq (rotacionIzquierda(nodo->obtenerHijoIzq()));
        return rotacionDerecha(nodo);
    }

    // Derecha Izquierda
    if (balance < -1 && balanceo(nodo->obtenerHijoDer()) > 0) {
        nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
        return rotacionIzquierda(nodo);
    }

    return nodo; // Ya está balanceado
}

// Inserción recursiva
template <class T>
NodoBinario<T>* ArbolAVL<T>::insertarRec(NodoBinario<T>* nodo, T val) {
    // Realiza la inserción estándar
    if (nodo == nullptr) {
        return new NodoBinario<T>(val);
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val));
    } else {
        return nodo; // Duplicado
    }

    // Balancea el nodo
    return balancear(nodo);
}

// Función pública para insertar un valor
template <class T>
void ArbolAVL<T>::insertar(T val) {
    raiz = insertarRec(raiz, val);
}

// Elimina un nodo y balancea el árbol
template <class T>
NodoBinario<T>* ArbolAVL<T>::eliminarRec(NodoBinario<T>* nodo, T val) {
    if (nodo == nullptr) {
        return nodo;
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminarRec(nodo->obtenerHijoIzq(), val));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminarRec(nodo->obtenerHijoDer(), val));
    } else {
        // Nodo con un solo hijo o sin hijo
        if (nodo->obtenerHijoIzq() == nullptr) {
            NodoBinario<T>* temp = nodo->obtenerHijoDer();
            delete nodo;
            return temp;
        } else if (nodo->obtenerHijoDer() == nullptr) {
            NodoBinario<T>* temp = nodo->obtenerHijoIzq();
            delete nodo;
            return temp;
        }

        // Nodo con dos hijos
        NodoBinario<T>* temp = encontrarMinimo(nodo->obtenerHijoDer());
        nodo->fijarDato(temp->obtenerDato());
        nodo->fijarHijoDer(eliminarRec(nodo->obtenerHijoDer(), temp->obtenerDato()));
    }

    return balancear(nodo);

    /* Obtiene el balance del nodo actual
    int balance = balanceo(nodo);

    // Si el nodo está desbalanceado, hay 4 casos a manejar:

    // Rotación derecha simple
    if (balance > 1 && balanceo(nodo->obtenerHijoIzq()) >= 0) {
        return rotacionDerecha(nodo);
    }

    // Rotación izquierda simple
    if (balance < -1 && balanceo(nodo->obtenerHijoDer()) <= 0) {
        return rotacionIzquierda(nodo);
    }

    // Rotación izquierda-derecha
    if (balance > 1 && balanceo(nodo->obtenerHijoIzq()) < 0) {
        nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
        return rotacionDerecha(nodo);
    }

    // Rotación derecha-izquierda
    if (balance < -1 && balanceo(nodo->obtenerHijoDer()) > 0) {
        nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
        return rotacionIzquierda(nodo);
    }

    return nodo; */
}

// Encuentra el nodo con el valor mínimo (más a la izquierda)
template <class T>
NodoBinario<T>* ArbolAVL<T>::encontrarMinimo(NodoBinario<T>* nodo) {
    NodoBinario<T>* actual = nodo;
    while (actual->obtenerHijoIzq() != nullptr) {
        actual = actual->obtenerHijoIzq();
    }
    return actual;
}

// Eliminar nodo público
template <class T>
void ArbolAVL<T>::eliminar(T val) {
    raiz = eliminarRec(raiz, val);
}


#endif // ARBOLAVL_HXX_INCLUDED
