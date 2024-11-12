#include <iostream>
#include "ArbolKD.h"

int main()
{
    ArbolKD arbol;

    // Crear algunos puntos para insertar
    Punto p1 = {32, 25};
    Punto p2 = {30, 35};
    Punto p3 = {35, 30};
    Punto p4 = {37, 12};
    Punto p5 = {25, 45};
    Punto p6 = {45, 32};
    Punto p7 = {5, 15};
    Punto p8 = {40, 42};

    // Insertar puntos en el árbol
    arbol.insertar(p1);
    arbol.insertar(p2);
    arbol.insertar(p3);
    arbol.insertar(p4);
    arbol.insertar(p5);
    arbol.insertar(p6);
    arbol.insertar(p7);
    arbol.insertar(p8);

    // Imprimir en diferentes órdenes
    std::cout << "Recorrido en pre-orden:" << std::endl;
    arbol.preOrden();

    std::cout << "\nRecorrido en in-orden:" << std::endl;
    arbol.inOrden();

    std::cout << "\nRecorrido en pos-orden:" << std::endl;
    arbol.posOrden();

    std::cout << "\nRecorrido en nivel-orden:" << std::endl;
    arbol.nivelOrden();
    std::cout << std::endl;

    // Casos de prueba para vecino más cercano

    // Caso 1: (36, 30) -> Vecino más cercano debería ser (35, 30)
    Punto puntoPrueba1 = {36, 30};
    NodoKD *vecino1 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba1);
    if (vecino1 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba1.x << ", " << puntoPrueba1.y << ") es ("
                  << vecino1->obtenerDato().x << ", " << vecino1->obtenerDato().y << ")" << std::endl;
    }

    // Caso 2: (18, 20) -> Vecino más cercano debería ser (5, 15)
    Punto puntoPrueba2 = {18, 20};
    NodoKD *vecino2 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba2);
    if (vecino2 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba2.x << ", " << puntoPrueba2.y << ") es ("
                  << vecino2->obtenerDato().x << ", " << vecino2->obtenerDato().y << ")" << std::endl;
    }

    // Caso 3: (46, 42) -> Vecino más cercano debería ser (40, 42)
    Punto puntoPrueba3 = {46, 42};
    NodoKD *vecino3 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba3);
    if (vecino3 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba3.x << ", " << puntoPrueba3.y << ") es ("
                  << vecino3->obtenerDato().x << ", " << vecino3->obtenerDato().y << ")" << std::endl;
    }

    // Caso 4: (28, 40) -> Vecino más cercano debería ser (30, 35)
    Punto puntoPrueba4 = {28, 40};
    NodoKD *vecino4 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba4);
    if (vecino4 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba4.x << ", " << puntoPrueba4.y << ") es ("
                  << vecino4->obtenerDato().x << ", " << vecino4->obtenerDato().y << ")" << std::endl;
    }

    // Caso 5: (38, 15) -> Vecino más cercano debería ser (37, 12)
    Punto puntoPrueba5 = {38, 15};
    NodoKD *vecino5 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba5);
    if (vecino5 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba5.x << ", " << puntoPrueba5.y << ") es ("
                  << vecino5->obtenerDato().x << ", " << vecino5->obtenerDato().y << ")" << std::endl;
    }

    // Caso 6: (41, 35) -> Vecino más cercano debería ser (40, 42)
    Punto puntoPrueba6 = {41, 35};
    NodoKD *vecino6 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba6);
    if (vecino6 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba6.x << ", " << puntoPrueba6.y << ") es ("
                  << vecino6->obtenerDato().x << ", " << vecino6->obtenerDato().y << ")" << std::endl;
    }

    // Caso 7: (28, 13) -> Vecino más cercano debería ser (37, 12)
    Punto puntoPrueba7 = {28, 13};
    NodoKD *vecino7 = arbol.vecinoCercano(arbol.obtenerRaiz(), puntoPrueba7);
    if (vecino7 != NULL)
    {
        std::cout << "El vecino más cercano a (" << puntoPrueba7.x << ", " << puntoPrueba7.y << ") es ("
                  << vecino7->obtenerDato().x << ", " << vecino7->obtenerDato().y << ")" << std::endl;
    }

    return 0;
}
