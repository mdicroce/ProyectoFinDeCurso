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
    aliados = crearListaAliados(charas);
    while (aliados != NULL)
    {
        enemigos = crearListaEnemigos(charas);

    }

}

int main()
{
    srand (time(NULL));
    inicioDePartida();
    return 0;
}
