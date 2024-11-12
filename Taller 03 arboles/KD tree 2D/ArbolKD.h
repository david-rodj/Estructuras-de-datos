#ifndef __ARBOLKD__H__
#define __ARBOLKD__H__
#include "NodoKD.h"

class ArbolKD
{
protected:
    NodoKD *raiz;

public:
    ArbolKD();
    ArbolKD(Punto val);
    ~ArbolKD();
    Punto datoRaiz();
    NodoKD *obtenerRaiz();
    void fijarRaiz(NodoKD *n_raiz);
    bool esVacio();
    bool insertar(Punto val);
    NodoKD *insertarRec(NodoKD *nodo, Punto val, bool &insertado, char dimension);
    NodoKD *cercano(NodoKD *n1, NodoKD *n2, Punto val);
    NodoKD *vecinoCercano(NodoKD *raiz, Punto val);
    void vecinoCercanoRec(NodoKD *nodo, Punto val, char dimension, NodoKD *&mejorNodo, int &mejorDist);
    // Recorridos
    void preOrden();
    void preOrden(NodoKD *nodo);
    void inOrden();
    void inOrden(NodoKD *nodo);
    void posOrden();
    void posOrden(NodoKD *nodo);
    void nivelOrden();
};

#include "ArbolKD.hxx"

#endif