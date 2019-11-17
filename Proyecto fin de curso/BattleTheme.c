#include "BattleTheme.h"
nodoPer * cola = NULL;
EstructuradeTiempo datos [30];
nodoPer * calculoAtaque (nodoPer *atacante, nodoPer *defensor)
{
    int danio;
    if (rand()%100 <= atacante->chara.suerte)
    {
        danio = atacante->chara.fuerza * 2;
    }
    else
    {
        danio = atacante->chara.fuerza;
    }
    danio -= defensor->chara.defenza;
    if (rand ()%100 <= defensor->chara.suerte)
    {
        danio = danio/2;
    }
    defensor->chara.vida -= danio;

    return defensor;
}

nodoPer * eliminarEnemigo (nodoPer * aliados)
{
    while (aliados != NULL)
    {
        if (aliados->chara.vida <= 0)
        {
            aliados = borrarNodo(aliados,aliados->chara);
        }
        aliados = aliados->siguiente;
    }
    return aliados;
}
void agregarACola (nodoPer *nodoAAgregar)
{
    nodoPer * aux = cola;
    nodoAAgregar ->siguiente = NULL;
    nodoAAgregar ->anterior = NULL;
    cola = ColaAgregar(aux,nodoAAgregar);
}
int pasarAEstructura(nodoPer * soldados,int i)
{
    while (soldados != NULL)
    {
        strcpy(datos[i].nombre,soldados->chara.nombre);
        datos[i].tiempoBase = 100 - soldados->chara.agilidad;
        datos[i].tiempoTranscurrido = datos[i].tiempoBase;
        soldados = soldados ->siguiente;
        i++;
    }
    return i;
}
brindarTurno (nodoPer *aliados, nodoPer * enemigos)
{
    int validos;
    nodoPer * aux;
    validos = pasarAEstructura(aliados,0);
    validos = pasarAEstructura(enemigos,validos);
    while (1)
    {
        for (int i = 0;i<validos;i++)
        {
            datos [i].tiempoTranscurrido -- ;
            if (datos[i].tiempoTranscurrido == 0)
            {
                aux = buscarNodo(datos.nombre,aliados);
                if (aux == NULL)
                {
                    aux = buscarNodo(datos.nombre,enemigos);
                }
                agregarACola(aux);
            }
        }
        if (cola != NULL)
        {
            ColaQuitar();
            DarleTurno ();
        }
        Sleep(500);
    }
}
