#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"

personajes roberto[4];
void mostrar (nodoPer *lista)
{
    nodoPer *aux = lista;
    while (lista != NULL)
    {
        printf("\t\nsususu%i",aux->chara.vida);
        aux = aux ->siguiente;
    }
    printf("\n");
}

int main()
{
    return 0;
}
