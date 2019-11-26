#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"
#include "IniciarPersonajes.h"
#include "IAenemigos.h"
#include "Graficos (alpha).h"
#include "MenuDeAccion.h"
nodoPer *enemigos;
nodoPer *aliados;
personajes charas[7];

void inicioDePartida ()
{
    int validos;
    nodoPer *aux,*aux2;
    aliados = crearListaAliados(charas);
    while (1)
    {
        enemigos = crearListaEnemigos(charas);
        aux = enemigos;
        while (aux != NULL)
        {
            printf("\n%i",aux->chara.vida);
            aux = aux->siguiente;
        }
        enemigos = eliminarEnemigo(enemigos);
        printf("\n");
        aux = enemigos;
        while (aux != NULL)
        {
            printf("\n%i",aux->chara.vida);
            aux = aux->siguiente;
        }
        system("pause"),
        validos = previaCombate(aliados,enemigos);
        iniciarCombate(aliados,enemigos,validos);
    }
}

int main()
{
    srand (time(NULL));
    inicioDePartida();
    return 0;
}
