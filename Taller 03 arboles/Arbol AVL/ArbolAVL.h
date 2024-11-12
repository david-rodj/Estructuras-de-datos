#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED

#include "NodoBinario.h"

template < class T >
class ArbolAVL {
protected:
    NodoBinario<T>* raiz;
public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    bool insertarRaiz(NodoBinario<T>* val);
    int altura();
    int altura(NodoBinario<T>* nodo);
    int tamano();
    bool buscar(T val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    NodoBinario<T>* obtenerSucesor(NodoBinario<T>* nodo);
    int balanceo(NodoBinario<T>* nodo);
    NodoBinario<T>* balancear(NodoBinario<T>* nodo);
    NodoBinario<T>* insertarRec(NodoBinario<T>* nodo, T val);
    void insertar(T val);
    NodoBinario<T>* eliminarRec(NodoBinario<T>* nodo, T val);
    NodoBinario<T>* encontrarMinimo(NodoBinario<T>* nodo);
    void eliminar(T val);
    NodoBinario<T>* rotacionDerecha(NodoBinario<T>* y);
    NodoBinario<T>* rotacionIzquierda(NodoBinario<T>* x);
};

#include "ArbolAVL.hxx"

#endif // ARBOLAVL_H_INCLUDED
