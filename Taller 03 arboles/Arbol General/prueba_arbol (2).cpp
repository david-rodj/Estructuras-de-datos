/************************************
 Nombres: Daniel Galvis
 TEMA: TALLER ARBOLES
 FECHA: 04/10/2024
 ***********************************/

#include <iostream>
#include <string>
#include "arbol.h"

using namespace std;

int main(){
    // Crea un árbol con 5 como valor inicial de la raíz
    Arbol<int> arbol(5);

    // Inserta nodos con los valores especificados como hijos del nodo con valor 5
    arbol.insertarNodo(5, 6);
    arbol.insertarNodo(5, 7);
    arbol.insertarNodo(5, 8);

    // Inserta nodos con los valores especificados como hijos de los nodos 6 y 7
    arbol.insertarNodo(6, 9);
    arbol.insertarNodo(6, 10);
    arbol.insertarNodo(7, 11);

    // Recorre el árbol en preorden e imprime los valores
    arbol.preOrden();

    return 0; // Fin del programa
}
