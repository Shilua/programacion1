#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
typedef struct
{
    int numero;
    char nombre[50];
}eEstructura;

int loadLista(ArrayList* lista);

void listarLista(ArrayList* lista);

void printEstructura(eEstructura* estruct);

int comparaNumero(eEstructura* num1, eEstructura* num2);

int comparaNombre(eEstructura* nombre1, eEstructura* nombre2);
