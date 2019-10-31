#ifndef FLISTASPERSONAJES_H_INCLUDED
#define FLISTASPERSONAJES_H_INCLUDED



#endif // FLISTASPERSONAJES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
typedef struct
{
    int vida;
    int defenza;
    int agilidad;
    int mana;
    char nombre[20];
    int tipo;
}personajes;
typedef struct
{
    personajes chara;
    struct nodoPer *siguiente;
    struct nodoPer *anterior;
}nodoPer;

nodoPer * inicLista (void);
nodoPer *  crearNodo (nodoPer *nuevoNodo,personajes dato);
nodoPer * agregarNodo (nodoPer *lista, nodoPer *nuevoNodo);
nodoPer * eliminarNodo (nodoPer *lista, personajes dato);
nodoPer * borrarLista (nodoPer *lista);
