#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "FListasPersonajes.h"

personajes roberto[2];

int main()
{
    nodoPer * roberto22 = inicLista();
    nodoPer * nuevoNodo;
    for (int i = 0; i<2; i++)
    {
        roberto [i].agilidad=0;
        roberto [i].defenza = 0;
        roberto [i].mana =0;
        roberto [i].tipo =0;
        roberto [i].vida = 0;
        strcpy(roberto[i].nombre,"nombre");
        nuevoNodo=crearNodo(nuevoNodo,roberto[i]);
        agregarNodo(&roberto22,nuevoNodo);
    }
    if (roberto22==NULL)
    {
        printf("hola");
    }
    strcpy(roberto[0].nombre,"nombre");
    roberto22 = eliminarNodo(roberto22,roberto[0]);
    if (roberto22==NULL)
    {
        printf("hola");
    }
    return 0;
}
