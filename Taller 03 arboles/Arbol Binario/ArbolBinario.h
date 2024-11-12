#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
protected:
    NodoBinario<T> *raiz;
public:
    ArbolBinario();
    bool esVacio();
    T& datoRaiz();
    int altura();
    int tamano();
    void insertar(T& val);
    bool eliminar(T& val);
    NodoBinario<T>* buscar(T& val);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif
