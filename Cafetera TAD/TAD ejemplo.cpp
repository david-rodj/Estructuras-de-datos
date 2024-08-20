/********************************************************
Pontificia Universidad Javeriana
Autor: David rodriguez
Fecha: 13/06/2024
Materia: Estructuras de datos
Tema: TAD
********************************************************/

#include <iostream>
#include "Cafetera.h" 

int main(){
  Cafetera* cafetera = new Haceb();
  cafetera->capuchino(); cafetera->tinto();
  delete cafetera;

  cafetera = new Oster();
  cafetera->capuchino(); cafetera->tinto();
  delete cafetera;

  return 0;
}
