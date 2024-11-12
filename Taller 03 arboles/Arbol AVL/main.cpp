#include <iostream>
#include "ArbolAVL.h"
#include <list>

//using namespace std;
int main () {
    ArbolAVL<int> arbol;
    NodoBinario<int>* nodoRaiz = new NodoBinario<int>(2);
    arbol.insertarRaiz(nodoRaiz);
    arbol.insertar(15);
    arbol.insertar(4);
    arbol.insertar(10);
    arbol.insertar(21);
    arbol.insertar(30);
    arbol.insertar(5);
    arbol.insertar(19);
    arbol.insertar(38);
    arbol.insertar(27);
    arbol.insertar(8);

    std:: cout<< "Arbol en preorden: ";
    arbol.preOrden();
    std:: cout << std::endl;
    std:: cout<< "Arbol en posorden: ";
    arbol.posOrden();
    std:: cout << std::endl;
    std:: cout<< "Arbol en nivelorden: ";
    arbol.nivelOrden();
    std:: cout << std::endl;
    std:: cout<< "Arbol en inOrden: ";
    arbol.inOrden();
    std:: cout << std::endl;


return 0;
}
