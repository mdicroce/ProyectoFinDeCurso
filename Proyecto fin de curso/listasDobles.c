#include "listasDobles.h"

nodoPer * inicLista()
{
    return NULL;
}
nodoPer * crearNodo (personajes datos)
{
    nodoPer * nuevo = (nodoPer*)malloc(sizeof(nodoPer));
    nuevo ->chara = datos;
    nuevo -> siguiente = NULL;
    nuevo -> anterior = NULL;
    return nuevo;
}
nodoPer * agregarPpio (nodoPer * lista, nodoPer * nuevoNodo)
{
   nuevoNodo->siguiente = lista;
    if(lista != NULL)
       lista->anterior=nuevoNodo;
    return nuevoNodo;
}
nodoPer * buscarUltimo(nodoPer * lista)
{
    nodoPer *aux = lista;
    if (lista == NULL)
    {
        aux = NULL;
    }
    else
    {
         while (aux ->siguiente != NULL)

        {
            aux->anterior = aux;
            aux = aux ->siguiente;
        }
    }

    return aux;
}
nodoPer * buscarNodo(int dato, nodoPer * lista)
{
    nodoPer *aux = lista;
    while ((dato != aux ->chara.turno)&&(aux != NULL))
    {
        aux -> anterior = aux;
        aux = aux -> siguiente;
    }
    return aux;
}
nodoPer * agregarFinal(nodoPer * lista, nodoPer * nuevoNodo)
{
    nodoPer *aux=buscarUltimo(lista);
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->anterior = aux;
        aux->siguiente = nuevoNodo;
    }
    return lista;
}
nodoPer * borrarNodo(nodoPer * lista, personajes dato)
{
    nodoPer *aux = lista;
    nodoPer *ante;
    nodoPer *sig;
    while ((strcmp(aux ->chara.nombre,dato.nombre)!= 0)&&(aux != NULL))
    {
        //aux->anterior = aux;
        aux = aux ->siguiente;
    }
    if (aux != NULL)
    {
        if (aux == lista)
        {
            lista = aux->siguiente;
            if (aux->siguiente != NULL)
            {
                lista->anterior =NULL;
            }
            else if (aux->siguiente != NULL)
            {
                ante = aux ->anterior;
                sig = aux->siguiente;
                ante -> siguiente = aux ->siguiente;
                sig -> anterior = aux -> anterior;
            }
            else
            {
                ante = aux -> anterior;
                ante ->siguiente = NULL;
            }
            free(aux);
        }
    }
    return lista;
}

nodoPer * borrarTodaLaLista(nodoPer * lista)
{
    nodoPer *aux = buscarUltimo(lista);
    nodoPer *ante;
    while (aux ->anterior != NULL)
    {
        aux->anterior = ante;
        free(aux);
        aux = ante;
    }
    return lista;
}
void mostrarUnNodo(nodoPer * aux)
{
    printf("\n%i vida",aux->chara.vida);
}
void recorrerYmostrar(nodoPer * lista)
{
    nodoPer*aux = lista;
    while (aux  != NULL)
    {
        mostrarUnNodo(aux);
        aux = aux->siguiente;
    }
}
