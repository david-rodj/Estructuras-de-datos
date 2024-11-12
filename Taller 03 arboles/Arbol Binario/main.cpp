#include<iostream>
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== Menu de Opciones ===" << endl;
    cout << "1. Insertar un nodo" << endl;
    cout << "2. Recorrido en Preorden" << endl;
    cout << "3. Recorrido en Inorden" << endl;
    cout << "4. Recorrido en Postorden" << endl;
    cout << "5. Recorrido en NivelOrden" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    ArbolBinario<int> arbolito;
    int opcion, valor;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor para insertar: ";
                cin >> valor;
                arbolito.insertar(valor);
                cout << "Nodo insertado!" << endl;
                break;

            case 2:
                cout << "Recorrido en Preorden:" << endl;
                arbolito.preOrden();
                break;

            case 3:
                cout << "Recorrido en Inorden:" << endl;
                arbolito.inOrden();
                break;

            case 4:
                cout << "Recorrido en Postorden:" << endl;
                arbolito.posOrden();
                break;

            case 5:
                cout << "Recorrido en NivelOrden:" << endl;
                arbolito.nivelOrden();
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}
