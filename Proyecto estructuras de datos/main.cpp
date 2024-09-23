/********************************************************
Pontificia Universidad Javeriana

Grupo: David Rodriguez Jurado.
Juan Sebastian Rodriguez Pabon. 
Julian Perez Gomes. 
Jan Marco Muñoz Pineda. 
Daniel Galvis Betancourth. 

Fecha: 06/09/2024

Materia: Estructuras de datos
********************************************************/

/********************************************************
Proyecto Mallas poligonales
********************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include "Sistema.h"

using namespace std;

/**
 * Enumeración para los comandos disponibles en el sistema.
 */
enum class Comando
{
    CARGAR,
    LISTADO,
    ENVOLVENTE,
    DESCARGAR,
    GUARDAR,
    SALIR,
    AYUDA,
    DESCONOCIDO
};

/**
 * Función para convertir una cadena a un comando.
 * 
 * @param str La cadena a convertir.
 * @return El comando correspondiente a la cadena.
 */
Comando stringToComando(const string &str)
{
    if (str == "cargar")
        return Comando::CARGAR;
    if (str == "listado")
        return Comando::LISTADO;
    if (str == "envolvente")
        return Comando::ENVOLVENTE;
    if (str == "descargar")
        return Comando::DESCARGAR;
    if (str == "guardar")
        return Comando::GUARDAR;
    if (str == "salir")
        return Comando::SALIR;
    if (str == "ayuda")
        return Comando::AYUDA;
    return Comando::DESCONOCIDO;
}

/**
 * Función para mostrar la ayuda general del sistema.
 */
void mostrarAyuda()
{
    cout << "\nComandos disponibles:\n"
         << "  cargar nombre_archivo: Carga un objeto 3D desde un archivo.\n"
         << "  listado: Lista los objetos cargados en memoria.\n"
         << "  envolvente nombre_objeto: Calcula la caja envolvente de un objeto.\n"
         << "  envolvente: Calcula la caja envolvente global de todos los objetos.\n"
         << "  descargar nombre_objeto: Elimina un objeto de la memoria.\n"
         << "  guardar nombre_objeto nombre_archivo: Guarda un objeto en un archivo.\n"
         << "  salir: Termina la ejecución de la aplicación.\n"
         << "  ayuda: Muestra esta ayuda.\n"
         << "  ayuda comando: Muestra la ayuda para un comando específico.\n\n";
}

/**
 * Función para mostrar la ayuda para un comando específico.
 * 
 * @param comando El comando para el que se desea mostrar la ayuda.
 */
void mostrarAyudaComando(const string &comando)
{
    if (comando == "cargar")
    {
        cout << "\nUso: cargar nombre_archivo\n"
             << "  Carga un objeto 3D desde un archivo.\n\n";
    }
    else if (comando == "listado")
    {
        cout << "\nUso: listado\n"
             << "  Lista los objetos cargados en memoria.\n\n";
    }
    else if (comando == "envolvente")
    {
        cout << "\nUso: envolvente nombre_objeto\n"
             << "  Calcula la caja envolvente de un objeto.\n"
             << "  \nUso: envolvente\n"
             << "  Calcula la caja envolvente global de todos los objetos.\n\n";
    }
    else if (comando == "descargar")
    {
        cout << "\nUso: descargar nombre_objeto\n"
             << "  Elimina un objeto de la memoria.\n\n";
    }
    else if (comando == "guardar")
    {
        cout << "\nUso: guardar nombre_objeto nombre_archivo\n"
             << "  Guarda un objeto en un archivo.\n\n";
    }
    else if (comando == "salir")
    {
        cout << "\nUso: salir\n"
             << "  Termina la ejecución de la aplicación.\n\n";
    }
    else
    {
        cout << "\nComando no reconocido.\n\n";
        mostrarAyuda();
    }
}

int main()
{
    Sistema s;
    string input, parametro, comandoStr, nombreObjeto, nombreArchivo;

    while (true)
    {
        input.clear();
        parametro.clear();
        comandoStr.clear();
        nombreObjeto.clear();
        nombreArchivo.clear();
        
        cout << "$ ";
        getline(cin, input); // Lee toda la línea de entrada del usuario

        stringstream ss(input);
        ss >> comandoStr;
        Comando cmd = stringToComando(comandoStr);

        // Procesar los comandos
        switch (cmd)
        {
        case Comando::CARGAR:
            ss >> parametro;
            if (!parametro.empty())
            {
                s.cargarObjeto(parametro);
            }
            else
            {
                cout << "\nEl comando 'cargar' requiere un parámetro (nombre del archivo).\n\n";
            }
            break;
        case Comando::LISTADO:
            ss >> parametro;
            if (parametro.empty())
            {
                s.listado();
            }
            else
            {
                cout << "\nEl comando 'listado' no requiere parámetros.\n\n";
            }
            break;
        case Comando::ENVOLVENTE:
            ss >> parametro;
            if (!parametro.empty())
            {
                s.envolvente(parametro);
            }
            else
            {
                s.envolventeGlobal();
            }
            break;
        case Comando::DESCARGAR:
            ss >> parametro;
            if (!parametro.empty())
            {
                s.descargar(parametro);
            }
            else
            {
                cout << "\nEl comando 'descargar' requiere un parámetro (nombre del objeto).\n\n";
            }
            break;
        case Comando::GUARDAR:
        {
            ss >> nombreObjeto >> nombreArchivo;

            if ((!nombreArchivo.empty()) && (!nombreObjeto.empty()))
            {
                s.guardar(nombreObjeto, nombreArchivo);
            }
            else
            {
                cout << "\nEl comando 'guardar' requiere dos parámetros (nombre del objeto y nombre del archivo).\n\n";
            }
            break;
        }
        case Comando::SALIR:
            ss >> parametro;
            if (parametro.empty())
            {
                return 0;
            }
            else  
            {
                cout << "\nEl comando 'salir' no requiere parámetros.\n\n";
            }
            break;
        case Comando::AYUDA:
            ss >> parametro;
            if (parametro.empty())
            {
                mostrarAyuda();
            }
            else
            {
                mostrarAyudaComando(parametro);
            }
            break;
        default:
            cout << "\nComando no reconocido. Usa 'ayuda' para ver la lista de comandos.\n\n";
            break;
        }
    }

    return 0;
}