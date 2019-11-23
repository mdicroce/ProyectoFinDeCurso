#include "Listas.h"

nodo * inicListaSimple()
{
    return NULL;
}
nodo * crearNodoSimple (int dato)
{
    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo ->dato = dato;
    nuevo ->siguiente = NULL;
    return nuevo;
}
nodo * agregarPpioSimple (nodo * lista, nodo * nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo ->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}
nodo * buscarUltimoSimple(nodo * lista)
{
    nodo*seg = lista;
    if (lista == NULL)
    {

    }
    else
    {
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}
nodo * buscarNodoSimple(int dato, nodo * lista)
{
    nodo *seg = lista;
    nodo *anterior;
    if (lista != NULL)
    {
        while ((dato != lista->dato)&&(seg!= NULL))
        {
            seg= seg->siguiente;
        }
    }
    return seg;
}
nodo * agregarFinalSimple(nodo * lista, nodo * nuevoNodo)
{
    nodo * seg;
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if (lista ->siguiente == NULL)
    {
        lista->siguiente = nuevoNodo;
    }
    else
    {
        seg = buscarUltimo(lista);
        seg ->siguiente = nuevoNodo;
    }
    return lista;
}
nodo * borrarNodoSimple(nodo * lista, int dato)
{
    nodo *seg;
    nodo *ante;

    if ((lista != NULL) && (dato == lista->dato))
    {
        nodo * aux = lista;
        lista = lista -> siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while ((dato != lista->dato)&&(seg != NULL))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if (seg != NULL)
        {
            ante ->siguiente = seg ->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo * borrarTodaLaListaSimple (nodo * lista)
{
    nodo*seg = lista;
    nodo * next;
    while (seg != NULL)
    {
        next = seg ->siguiente;
        free(seg);
        seg = next;
    }
    return seg;
}
nodo * borrarNodoPrimeroSimple(nodo * lista)
{
    nodo * aux = lista->siguiente;
    free(lista);
    return aux;
}
