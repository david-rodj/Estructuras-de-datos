#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template<class T>
class NodoBinario {
protected:
    T dato;
    NodoBinario *hijoIzq, *hijoDer;
public:
    NodoBinario();
    T& obtenerDato();
    void fijarDato(T& val);
    NodoBinario* obtenerHijoIzq();
    NodoBinario* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario *izq);
    void fijarHijoDer(NodoBinario *der);
    int altura();
    int tamano();
    void insertar(T& val);
    NodoBinario* buscar(T& val);
    NodoBinario* extremo_der();
    NodoBinario* extremo_izq();
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "NodoBinario.hxx"
#endif
