#ifndef __NODOKD__H__
#define __NODOKD__H__
#include "Punto.h"

class NodoKD
{
protected:
    Punto dato;
    NodoKD *hijoIzq;
    NodoKD *hijoDer;

public:
    NodoKD();
    NodoKD(Punto val);
    ~NodoKD();
    bool esHoja();
    Punto obtenerDato();
    void fijarDato(Punto val);
    NodoKD *obtenerHijoIzq();
    NodoKD *obtenerHijoDer();
    void fijarHijoIzq(NodoKD *izq);
    void fijarHijoDer(NodoKD *der);
};

#include "NodoKD.hxx"
#endif