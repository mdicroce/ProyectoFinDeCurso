#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
typedef struct
{
    int vida;
    int defenza;
    int agilidad;
    int fuerza;
    int inteligencia;
    int suerte;
    char nombre[20];
    int tipo;
    int lvl;
}personajes;
typedef struct
{
    personajes chara;
    struct nodoPer *siguiente;
    struct nodoPer *anterior;
}nodoPer;

nodoPer * inicLista();
nodoPer * crearNodo (personajes dato);
nodoPer * agregarPpio (nodoPer * lista, nodoPer * nuevoNodo);
nodoPer * buscarUltimo(nodoPer * lista);
nodoPer * buscarNodo(char nombre[20], nodoPer * lista);
nodoPer * agregarFinal(nodoPer * lista, nodoPer * nuevoNodo);
nodoPer * borrarNodo(nodoPer * lista, personajes dato);
nodoPer * agregarEnOrden(nodoPer * lista, nodoPer * nuevoNodo);
nodoPer * borrarTodaLaLista(nodoPer * lista);
int sumarEdadesLista(nodoPer * lista);
void mostrarUnNodo(nodoPer * aux);
void recorrerYmostrar(nodoPer * lista);
#endif // INICIARPERSONAJES_H_INCLUDED
