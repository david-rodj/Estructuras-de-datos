#include "NodoKD.h"

NodoKD::NodoKD()
{
    Punto p;
    p.x = 0;
    p.y = 0;

    this->dato = p;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoKD::NodoKD(Punto p)
{
    this->dato = p;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

NodoKD::~NodoKD()
{
    if (this->hijoIzq != NULL)
    {
        delete this->hijoIzq;
    }
    if (this->hijoDer != NULL)
    {
        delete this->hijoDer;
    }
}

Punto NodoKD::obtenerDato()
{
    return dato;
}

void NodoKD::fijarDato(Punto val)
{
    dato = val;
}

NodoKD *NodoKD::obtenerHijoIzq()
{
    return hijoIzq;
}

void NodoKD::fijarHijoIzq(NodoKD *izq)
{
    this->hijoIzq = izq;
}

NodoKD *NodoKD::obtenerHijoDer()
{
    return hijoDer;
}

void NodoKD::fijarHijoDer(NodoKD *der)
{
    this->hijoDer = der;
}

bool NodoKD::esHoja()
{
    return (this->hijoDer == NULL) && (this->hijoIzq == NULL);
}