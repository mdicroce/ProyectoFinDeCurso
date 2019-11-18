#include "FListasPersonajes.h"

nodoPer * inicLista (void)
{
    return NULL;
}
nodoPer * crearNodo (nodoPer *nuevoNodo,personajes dato)
{
    nuevoNodo = (nodoPer*)malloc(sizeof (nodoPer));

    nuevoNodo->chara = dato;


    nuevoNodo ->siguiente = NULL;
    nuevoNodo -> anterior = NULL;

}
nodoPer * agregarNodo (nodoPer *lista, nodoPer *nuevoNodo)
{
    if (lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
    }
    return lista;
}
nodoPer * eliminarNodo (nodoPer *lista, personajes dato)
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
nodoPer * borrarLista (nodoPer *lista)
{
    if (lista== NULL)
    {
    }
    else
    {
        lista = borrarLista(lista->siguiente);
        free(lista);


    }
    return lista;
}
