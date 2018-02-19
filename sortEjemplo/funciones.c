#include "funciones.h"


int loadLista(ArrayList* lista)
{
    int returnAux = -1;

    if(lista!=NULL)
    {
        eEstructura* estruc;
        char nombre[50];
        char numeroAux[2];
        int aux;

        FILE* archivo;
        archivo = fopen("lista.csv","r");
        if(archivo == NULL)
        {
            fclose(archivo);
        }
        else
        {
            returnAux = 0;
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^\n]\n",numeroAux,nombre);
                aux = atoi(numeroAux);
                estruc = (eEstructura*)malloc(sizeof(eEstructura));
                strcpy(estruc->nombre,nombre);
                estruc->numero = aux;
                if(estruc != NULL)
                {
                    lista->add(lista,estruc);
                }
            }
            fclose(archivo);
        }
    }
    return returnAux;
}

void listarLista(ArrayList* lista)
{
    int i, tam;
    tam = lista->len(lista);
    printf("NUMERO\tNOMBRE\n");
    for(i=0;i<tam;i++)
    {
        printEstructura(lista->get(lista,i));
    }
}

void printEstructura(eEstructura* estruct)
{
    printf("%d\t%s\n",estruct->numero, estruct->nombre);
}

int comparaNumero(eEstructura* num1, eEstructura* num2)
{
    int returnAux = 0;

    if(num1->numero > num2->numero)
    {
        returnAux = 1;
    }
    else if(num1->numero < num2->numero)
    {
        returnAux = -1;
    }
    return returnAux;
}

int comparaNombre(eEstructura* nombre1, eEstructura* nombre2)
{
    int returnAux;
    returnAux = strcmp(nombre1->nombre,nombre2->nombre);
    return returnAux;
}
