#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"
#include "IniciarPersonajes.h"
void mostrarPrueba(nodoPer * aux)
{
    while (aux != NULL)
    {
        printf("\nVIDA%i\nDEFENZA%i\nAGILIDAD%i",aux->chara.vida,aux->chara.defenza,aux->chara.agilidad);
        printf("\n\n");
        aux = aux->siguiente;
    }
}

int main()
{
    personajes aladin [7];
    nodoPer * pucho;
    pucho = crearListaAliados(aladin);
    mostrarPrueba(pucho);
    return 0;
}
