#ifndef __QUADTREE__H__
#define __QUADTREE__H__

#include "nodo.h"

using namespace std;

template<class T>
class Arbol {
  protected:
    Nodo<T> *raiz;
  public:
	Arbol();
	Arbol(pair<T,T> val);
    bool esVacio();
    pair<T,T> obtenerRaiz();
    void fijarRaiz(Nodo<T>* root);
    void insertar(pair<T,T>);
    int altura();
    int tamano();
    void insertar(T& val);
    bool eliminar(T& val);
    Nodo<T>*  buscar(pair<T,T> val);
    void preOrden();
    void posOrden();
};

#include "quadtree.hxx"
#endif
