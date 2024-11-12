#include "NodoBinario.h"
#include <queue>

using namespace std;

template<class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

template<class T>
T& NodoBinario<T>::obtenerDato()
{
    return this->dato;
}

template<class T>
void NodoBinario<T>::fijarDato(T& val)
{
    this->dato = val;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return this->hijoDer;
}

template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
}

template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
}

template<class T>
int NodoBinario<T>::altura()
{
    if (this->hijoIzq == NULL && this->hijoDer == NULL)
    {
        return 1;
    }
    if (this->hijoIzq == NULL)
        return this->hijoDer->altura() + 1;
    else if (this->hijoDer == NULL)
        return this->hijoIzq->altura() + 1;

    return max(this->hijoIzq->altura(), this->hijoDer->altura()) + 1;
}

template<class T>
int NodoBinario<T>::tamano()
{
    if (this->hijoIzq == NULL && this->hijoDer == NULL)
    {
        return 1;
    }
    if (this->hijoIzq == NULL)
        return this->hijoDer->tamano() + 1;
    else if (this->hijoDer == NULL)
        return this->hijoIzq->tamano() + 1;

    return this->hijoIzq->tamano() + this->hijoDer->tamano() + 1;
}

template<class T>
void NodoBinario<T>::insertar(T& val)
{
    if (val > this->obtenerDato())
    {
        if (this->hijoDer == NULL)
        {
            NodoBinario* nuevo = new NodoBinario();
            nuevo->fijarDato(val);
            this->fijarHijoDer(nuevo);
        }
        else
        {
            this->hijoDer->insertar(val);
        }
    }

    if (val < this->obtenerDato())
    {
        if (this->hijoIzq == NULL)
        {
            NodoBinario* nuevo = new NodoBinario();
            nuevo->fijarDato(val);
            this->fijarHijoIzq(nuevo);
        }
        else
        {
            this->hijoIzq->insertar(val);
        }
    }
}

template<class T>
NodoBinario<T>* NodoBinario<T>::buscar(T& val)
{
    if (this->obtenerDato() == val)
    {
        return this;
    }

    if (val < this->obtenerDato())
    {
        if (this->hijoIzq != NULL)
            return this->hijoIzq->buscar(val);
        else
            return NULL;
    }
    else
    {
        if (this->hijoDer != NULL)
            return this->hijoDer->buscar(val);
        else
            return NULL;
    }
}

template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der()
{
    if (this->hijoDer != NULL)
        return this->hijoDer->extremo_der();
    else
        return this;
}

template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq()
{
    if (this->hijoIzq != NULL)
        return this->hijoIzq->extremo_izq();
    else
        return this;
}

template<class T>
void NodoBinario<T>::preOrden()
{
    cout << "\t" << this->obtenerDato() << endl;
    if (this->hijoIzq != NULL)
        this->hijoIzq->preOrden();
    if (this->hijoDer != NULL)
        this->hijoDer->preOrden();
}

template<class T>
void NodoBinario<T>::inOrden()
{
    if (this->hijoIzq != NULL)
        this->hijoIzq->inOrden();

    cout << "\t" << this->obtenerDato() << endl;

    if (this->hijoDer != NULL)
        this->hijoDer->inOrden();
}

template<class T>
void NodoBinario<T>::posOrden()
{
    if (this->hijoIzq != NULL)
        this->hijoIzq->posOrden();

    if (this->hijoDer != NULL)
        this->hijoDer->posOrden();

    cout << "\t" << this->obtenerDato() << endl;
}

template<class T>
void NodoBinario<T>::nivelOrden()
{
    queue<NodoBinario*> cola;
    cola.push(this);
    while (!cola.empty())
    {
        cout << "\t" << cola.front()->obtenerDato() << endl;
        if (cola.front()->hijoIzq != NULL)
        {
            cola.push(cola.front()->hijoIzq);
        }

        if (cola.front()->hijoDer != NULL)
        {
            cola.push(cola.front()->hijoDer);
        }
        cola.pop();
    }
}
