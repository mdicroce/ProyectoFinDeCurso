#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct {
     int dato;
     struct nodo * siguiente;
} nodo;

nodo * inicListaSimple();
nodo * crearNodoSimple (int dato);
nodo * agregarPpioSimple (nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimoSimple (nodo * lista);
nodo * buscarNodoSimple (int dato, nodo * lista);
nodo * agregarFinalSimple(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodoSimple(nodo * lista, int dato);
nodo * agregarEnOrdenSimple(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaListaSimple(nodo * lista);
