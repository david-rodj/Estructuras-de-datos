#include "ArbolKD.h"
#include <queue>
#include <limits>

ArbolKD::ArbolKD()
{
    this->raiz = NULL;
}

ArbolKD::~ArbolKD()
{
    if (this->raiz != NULL)
    {
        delete this->raiz;
        this->raiz = NULL;
    }
}

bool ArbolKD::esVacio()
{
    return this->raiz == NULL;
}

Punto ArbolKD::datoRaiz()
{
    return (this->raiz)->obtenerDato();
}

void ArbolKD::fijarRaiz(NodoKD *nodo)
{
    this->raiz = nodo;
}

NodoKD *ArbolKD::obtenerRaiz()
{
    return this->raiz;
}

bool ArbolKD::insertar(Punto val)
{
    bool insertado = false;
    this->raiz = insertarRec(this->raiz, val, insertado, 'x');
    return insertado;
}

NodoKD *ArbolKD::insertarRec(NodoKD *nodo, Punto val, bool &insertado, char dimension)
{
    if (nodo == NULL)
    {
        insertado = true;
        return new NodoKD(val);
    }

    if (val.x == nodo->obtenerDato().x && val.y == nodo->obtenerDato().y)
    {
        insertado = false; // DUPLICADO
        return nodo;
    }

    if (dimension == 'x')
    {
        if (val.x <= nodo->obtenerDato().x)
        {
            nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val, insertado, 'y'));
        }
        else if (val.x > nodo->obtenerDato().x)
        {
            nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val, insertado, 'y'));
        }
    }
    if (dimension == 'y')
    {
        if (val.y <= nodo->obtenerDato().y)
        {
            nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val, insertado, 'x'));
        }
        else if (val.y > nodo->obtenerDato().y)
        {
            nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val, insertado, 'x'));
        }
    }

    return nodo;
}

NodoKD *ArbolKD::vecinoCercano(NodoKD *raiz, Punto val)
{
    NodoKD *mejorNodo = NULL;
    int mejorD = std::numeric_limits<int>::max();
    vecinoCercanoRec(raiz, val, 'x', mejorNodo, mejorD);
    return mejorNodo;
}

void ArbolKD::vecinoCercanoRec(NodoKD *nodo, Punto val, char dimension, NodoKD *&mejorNodo, int &mejorDist)
{

    NodoKD *sigRama = NULL;
    NodoKD *otraRama = NULL;

    if (nodo == NULL)
        return;

    int distActual = val.distanciaEuclidiana(nodo->obtenerDato());
    if (distActual < mejorDist)
    {
        mejorDist = distActual;
        mejorNodo = nodo;
    }

    // Buscar nodo raiz cercano
    if (val.x == nodo->obtenerDato().x && val.y == nodo->obtenerDato().y)
    {
        std::cout << "Se encontro un punto igual" << std::endl;
        mejorNodo = nodo;
        return;
    }
    else if (dimension == 'x')
    {
        if (val.x <= nodo->obtenerDato().x)
        {
            sigRama = nodo->obtenerHijoIzq();
            otraRama = nodo->obtenerHijoDer();
        }
        else if (val.x > nodo->obtenerDato().x)
        {

            sigRama = nodo->obtenerHijoDer();
            otraRama = nodo->obtenerHijoIzq();
        }
    }
    else if (dimension == 'y')
    {
        if (val.y <= nodo->obtenerDato().y)
        {
            sigRama = nodo->obtenerHijoIzq();
            otraRama = nodo->obtenerHijoDer();
        }
        else if (val.y > nodo->obtenerDato().y)
        {
            sigRama = nodo->obtenerHijoDer();
            otraRama = nodo->obtenerHijoIzq();
        }
    }

    // Alternar dimensión para la siguiente recursión
    char nuevaDimension = (dimension == 'x') ? 'y' : 'x';

    vecinoCercanoRec(sigRama, val, nuevaDimension, mejorNodo, mejorDist);
    NodoKD *nodoVecino = cercano(mejorNodo, nodo, val);

    // Distancia entre la recta y el punto
    int distEje;
    if (dimension == 'x')
    {
        distEje = abs(val.x - nodo->obtenerDato().x);
    }
    else
    {
        distEje = abs(val.y - nodo->obtenerDato().y);
    }

    if (distEje < distActual)
    {
        vecinoCercanoRec(otraRama, val, nuevaDimension, mejorNodo, mejorDist);
        nodoVecino = cercano(mejorNodo, nodo, val);
    }
}

NodoKD *ArbolKD::cercano(NodoKD *n1, NodoKD *n2, Punto val)
{

    if (n2 == NULL)
        return n1;
    if (n1 == NULL)
        return n2;

    int distN1 = n1->obtenerDato().distanciaEuclidiana(val);
    int distN2 = n2->obtenerDato().distanciaEuclidiana(val);

    if (distN1 < distN2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

void ArbolKD::preOrden()
{
    if (!this->esVacio())
    {
        this->preOrden(this->raiz);
    }
}

void ArbolKD::preOrden(NodoKD *nodo)
{
    std::cout << nodo->obtenerDato() << " ";

    if (nodo->obtenerHijoIzq() != NULL)
    {
        this->preOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL)
    {
        this->preOrden(nodo->obtenerHijoDer());
    }
}

void ArbolKD::inOrden()
{
    if (!this->esVacio())
    {
        this->inOrden(this->raiz);
    }
}

void ArbolKD::inOrden(NodoKD *nodo)
{
    if (nodo != NULL)
    {
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout << nodo->obtenerDato() << " ";
        this->inOrden(nodo->obtenerHijoDer());
    }
}

void ArbolKD::posOrden()
{
    if (!this->esVacio())
    {
        this->posOrden(this->raiz);
    }
}

void ArbolKD::posOrden(NodoKD *nodo)
{
    if (nodo->obtenerHijoIzq() != NULL)
    {
        this->posOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL)
    {
        this->posOrden(nodo->obtenerHijoDer());
    }

    std::cout << nodo->obtenerDato() << " ";
}

void ArbolKD::nivelOrden()
{
    if (!this->esVacio())
    {
        std::queue<NodoKD *> cola;
        cola.push(this->raiz);
        NodoKD *nodo;

        while (!cola.empty())
        {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";

            if (nodo->obtenerHijoIzq() != NULL)
            {
                cola.push(nodo->obtenerHijoIzq());
            }

            if (nodo->obtenerHijoDer() != NULL)
            {
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}
