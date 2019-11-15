#ifndef INICIARPERSONAJES_H_INCLUDED
#define INICIARPERSONAJES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"
personajes  crearPersonajes (personajes characters []);
void  crearEnemigos (personajes enemy[]);
nodoPer * crearListaEnemigos (personajes enemys[]);
nodoPer * crearListaAliados(personajes aliados[]);




#endif // INICIARPERSONAJES_H_INCLUDED

