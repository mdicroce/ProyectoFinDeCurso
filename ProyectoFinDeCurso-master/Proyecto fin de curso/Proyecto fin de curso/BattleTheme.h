#ifndef BATTLETHEME_H_INCLUDED
#define BATTLETHEME_H_INCLUDED
#include "listasDobles.h"
#include "IniciarPersonajes.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char nombre[20];
    int tiempoBase;
    int tiempoTranscurrido;
}EstructuradeTiempo;

nodoPer * calculoAtaque (nodoPer *atacante, nodoPer *defensor);
nodoPer * eliminarEnemigo (nodoPer * aliados);
nodoPer * defenzaON (nodoPer *person);
nodoPer * defenzaOF (nodoPer *person);
nodoPer * curacion(nodoPer *aliado, nodoPer *trus);
nodoPer * buffDamage(nodoPer *aliado, nodoPer *trus);
nodoPer *debuffDamagge (nodoPer *aliado);


#endif // BATTLETHEME_H_INCLUDED
