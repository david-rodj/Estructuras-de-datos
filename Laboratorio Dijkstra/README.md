# Guia de compilación y ejecución del proyecto
En este archivo estará el paso a paso para compilar y ejecutar el proyecto en su totalidad, espero sea de de gran ayuda.


## Instalar Compilador g++ con MinGW para Windows (Puedes saltarte este paso si ya lo tienes o usas un sistema basado en Unix)
Para compilar este proyecto recomiendo `g++`, así que lo tendremos que instalar siguiendo la guia de [MSYS2](https://www.msys2.org/), este te instalara tanto `g++` como `gcc` y `gdb`.


## Compilación
Para compilar el proyecto, abriras la consola de tu preferencia, digitaras el siguiente comando remplazando los parametros segun tu necesidad:

```bash
g++ [nombre del fichero(s) a compilar (.cpp y .cxx)] -o [nombre del ejecutable]
```

## Ejecución
Para ejecutar el proyecto, digitaras el siguiente comando en la consola:

```bash
./[nombre del ejecutable] 
```
