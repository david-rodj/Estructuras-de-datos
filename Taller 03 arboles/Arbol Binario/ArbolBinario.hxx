#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

template<class T>
ArbolBinario<T>::ArbolBinario()
{
    this->raiz = NULL;
}

template<class T>
bool ArbolBinario<T>::esVacio()
{
    return this->raiz == NULL;
}

template<class T>
T& ArbolBinario<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}

template<class T>
int ArbolBinario<T>::altura()
{
    return this->raiz->altura();
}

template<class T>
int ArbolBinario<T>::tamano()
{
    return this->raiz->tamano();
}

template<class T>
void ArbolBinario<T>::insertar(T& val)
{
    if(this->raiz != NULL)
    {
        this->raiz->insertar(val);
    }
    else
    {
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz = nuevo;
    }
}

template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{
    NodoBinario<T>* borrar = this->buscar(val);
    if (borrar == NULL)
        return false;

    if (borrar->hijoIzq != NULL)
    {
        NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
        delete nuevo;
    }
    else if (borrar->hijoDer != NULL)
    {
        NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
        delete nuevo;
    }
    return true;
}

template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
    return this->raiz->buscar(val);
}

template<class T>
void ArbolBinario<T>::preOrden()
{
    this->raiz->preOrden();
}

template<class T>
void ArbolBinario<T>::inOrden()
{
    this->raiz->inOrden();
}

template<class T>
void ArbolBinario<T>::posOrden()
{
    this->raiz->posOrden();
}

template<class T>
void ArbolBinario<T>::nivelOrden()
{
    this->raiz->nivelOrden();
}
