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
    graficosInicio();
    instrucciones();
    int validos;
    nodoPer *aux,*aux2;
    aliados = crearListaAliados(charas);
    while (aliados != NULL)
    {
        enemigos = crearListaEnemigos(charas);
        aux = enemigos;
        enemigos = eliminarEnemigo(enemigos);
        aux = enemigos;
        system("cls");
        graficas(aliados,enemigos);
        aliados = brindarTurnos(aliados,enemigos);
    }
}

int main()
{
    srand (time(NULL));
    inicioDePartida();

    return 0;
}
