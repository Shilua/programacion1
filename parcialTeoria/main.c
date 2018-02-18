#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
}eFecha;

typedef struct
{
    int dni;
    char nombre[50];
    eFecha fechaNacimiento;
}ePersona;

ePersona* persona_new();

int ordenamiento(ArrayList* lista);

int guardarBinario (ArrayList* lista);

char* persona_getNombre(ePersona* persona);

int encontrar(char*,char);

int main()
{

    ArrayList* lista;
    lista = al_newArrayList();

    if(lista != NULL)
    {
        ePersona* nueva;
        int i;

        for(i=0;i<100;i++)
        {
            nueva = persona_new();
            if(nueva !=NULL)
            {
                lista->add(lista,nueva);
            }
        }
    }
    al_clear(lista);

   /*int vec[10] = {0,1,2,3,4,5,6,7,8,9};
   int* p;
   int i;
   p = vec;

   for(i=0;i<10;i++)
   {
        printf("%d\n", *(p+i));
        printf("%d\n", p[i]);
        printf("%d\n", &p[i]);
        printf("%d\n", p+i);
        system("pause");
   }*/

    return 0;
}

ePersona* persona_new()
{
    ePersona* nueva;
    nueva = (ePersona*)malloc(sizeof(ePersona));
    return nueva;
}

int ordenamiento(ArrayList* lista)
{
    int returnAux = 0;

    if(lista !=NULL)
    {
        int i,j,k;
        k = lista->len(lista);
        ePersona* persona1;
        ePersona* persona2;
        ePersona* personaAux;
        for(i=0;i<k-1;i++)
        {
            persona1 = lista->get(lista,i);
            for(j=i+1;j<k;j++)
            {
                persona2 = lista->get(lista,j);
                if(strcmp(persona1->nombre,persona2->nombre)>0)
                {
                    personaAux = persona1;
                    persona1 = persona2;
                    persona2 = personaAux;
                }
                else if(strcasecmp(persona1->nombre,persona2->nombre)==0)
                {
                    if(persona1->dni<persona2->dni)
                        {
                            personaAux = persona1;
                            persona1 = persona2;
                            persona2 = personaAux;
                        }
                }
            }
        }
    }

    return returnAux;
}

int guardarBinario (ArrayList* lista)
{
    int returnAux = 0;
    if(lista != NULL)
    {
        returnAux = 1;
        FILE* archivo;
        archivo = fopen("archivo.bin","wb");
        int i,j;
        j = lista->len(lista);
        ePersona* persona;
        for(i=0;i<j;i++)
        {
            persona = lista->get(lista,i);
            fwrite(persona,sizeof(ePersona),1,archivo);
        }
        fclose(archivo);
    }
    return returnAux;
}

char* persona_getNombre(ePersona* persona)
{
    return persona->nombre;
}

int encontrar(char* palabra,char letra)
{
    int returnAux = 0;

    if(palabra !=NULL)
    {
        int i,j;
        char aux;
        j = strlen(palabra);
        for(i=0;i<j;i++)
        {
            aux = *(palabra+i);
            if(aux == letra)
            {
                returnAux += returnAux;
            }
        }
    }

    return returnAux;
}
