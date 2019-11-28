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
    while ((aux != NULL)&&(dato != aux ->chara.turno))
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
    nodoPer * aBorrar=NULL;
    nodoPer * seg=NULL;

    if(lista!=NULL)
    {
        if(0 == strcmp(lista->chara.nombre,dato.nombre))
        {
            aBorrar=lista;

            lista=lista->siguiente;
            if(lista!=NULL)
                lista->anterior=NULL;

            free(aBorrar);
        }
        else
        {
            seg=lista->siguiente;
            while(seg!=NULL && 0 != strcmp(seg->chara.nombre,dato.nombre))
            {
                seg=seg->siguiente;
            }

            if( seg!= NULL)
            {
                nodoPer * anterior=seg->anterior; /// bajo a una variable el anterior

                anterior->siguiente = seg->siguiente; ///salteo el nodo que quiero eliminar.

                if(seg->siguiente) /// si existe el nodo siguiente
                {
                    nodoPer * siguiente = seg->siguiente;
                    siguiente->anterior=anterior;
                }
                free(seg); ///elimino el nodo.
            }

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
