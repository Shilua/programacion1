#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    /*ArrayList* lista;
    lista = al_newArrayList();

    if(lista != NULL)
    {
        //CARGA LA LISTA HARCODEADA
        loadLista(lista);
        printf("Lista sin ordenar\n");
        listarLista(lista);

        //ORDENA POR NUMERO
        printf("\n");
        al_sort(lista,comparaNumero,1);
        printf("Lista ordenada por numero\n");
        listarLista(lista);

        //ORDENA POR NOMBRE
        printf("\n");
        al_sort(lista,comparaNombre,1);

        printf("Lista ordenada por nombre\n");
        listarLista(lista);
    }*/
    int i;
    for(i=0;i<20;i++)
    {
        if((i%5)==0)
        {
            i++;
            printf("%d\n",i);
        }

    }
    return 0;
}
