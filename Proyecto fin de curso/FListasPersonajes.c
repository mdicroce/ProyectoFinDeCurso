#include "FListasPersonajes.h"

nodoPer * inicLista (void)
{
    return NULL;
}
nodoPer * crearNodo (nodoPer *nuevoNodo,personajes dato)
{
    nuevoNodo = (nodoPer*)malloc(sizeof (nodoPer));
    nuevoNodo ->siguiente = NULL;
    nuevoNodo -> anterior = NULL;

}
agregarNodo (nodoPer **lista, nodoPer *nuevoNodo)
{
    nuevoNodo -> siguiente = *lista;
    *lista = nuevoNodo;
}
nodoPer * eliminarNodo (nodoPer *lista, personajes dato)
{
    if (lista != NULL)
    {
        if (0==strcmp(dato.nombre,*lista->chara.nombre))
        {
            nodoPer *aux = lista;
            lista->anterior = NULL;
            free(aux);
        }
        else
        {
            lista = eliminarNodo(lista->siguiente,dato);
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
