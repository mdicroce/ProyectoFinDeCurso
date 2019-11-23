#include "BattleTheme.h"
int *turnosGuardados;
nodo * ColaDeTurnos;
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
nodoPer * defenzaON (nodoPer *person)
{
    person->chara.defenza = person ->chara.defenza *2;
    person ->chara.agilidad = person ->chara.agilidad *2;
    person ->chara.mod = 1;
    return person;
}
nodoPer * defenzaOF (nodoPer *person)
{
    person->chara.defenza = person->chara.defenza /2;
    person ->chara.agilidad = person ->chara.agilidad/2;
    return person;
}
nodoPer * curacion(nodoPer *aliado, nodoPer *trus)
{
    trus->chara.vida += aliado->chara.inteligencia;
    if (trus->chara.vida > trus->chara.vidaMax)
    {
        trus->chara.vida = trus->chara.vidaMax;
    }
    return trus;
}
nodoPer * buffDamage(nodoPer *aliado, nodoPer *trus)
{
    trus->chara.fuerza += (0.1 * aliado->chara.inteligencia);
    return trus;
}
nodoPer *debuffDamagge (nodoPer *aliado)
{
    aliado->chara.fuerza = aliado ->chara.fuerzaOrg;
    return aliado ;
}
int contarValidos (nodoPer * enemigos)
{
    int i = 4;
    nodoPer * aux = enemigos;
    while (aux != NULL)
    {
        i++;
        aux = aux ->siguiente;
    }
    return i;
}
void previaCombate(nodoPer* aliados, nodoPer *enemigos)
{
    nodoPer *auxAliados = aliados, *auxEnemigos = enemigos;
    int validos = contarValidos(enemigos);
    turnosGuardados = (int*)calloc(validos,sizeof(int));
    for (int i =0;i<4;i++)
    {
        turnosGuardados[i] =100 - auxAliados->chara.agilidad;
        auxAliados = auxAliados ->siguiente;
    }
    for (int i = 4; i<validos; i++)
    {
        turnosGuardados[i]= 100 - auxEnemigos ->chara.agilidad;
        auxEnemigos = auxEnemigos ->siguiente;
    }
}
void brindarTurnos (nodoPer **aliados,nodo** enemigos)
{
    nodoPer * datoBuscado;
    int deQuienEs;
    if (datoBuscado == NULL)
    {
        datoBuscado = buscarNodo(ColaDeTurnos->dato,*aliados);
        if (datoBuscado != NULL)
        {
            seleccionarAccion(aliados,enemigos,&datoBuscado);
        }
        else
        {
            datoBuscado = buscarNodo(ColaDeTurnos->dato,*enemigos);
            if (datoBuscado != NULL)
            {
                IA (aliados,enemigos,&datoBuscado);
            }
        }
    }


}
void determinarSiSiguenVivos (nodoPer *aliados,nodoPer *enemigos,int validos)
{
    nodoPer * auxAliados = aliados, *auxEnemigos = enemigos;
    for (int i = 0; i<validos;i++)
    {
        auxAliados=aliados;
        auxEnemigos = enemigos;
        while (auxAliados != NULL)
        {
            if (auxAliados->chara.turno == i)
            {
                if (auxAliados->chara.vida <= 0)
                {
                    turnosGuardados[i] = -1;
                }
            }
            auxAliados = auxAliados->siguiente;
        }
        while (auxEnemigos != NULL)
        {
            if (auxEnemigos->chara.turno == i)
            {
                if (auxEnemigos->chara.vida  <= 0)
                {
                    turnosGuardados[i] = -1;
                }
            }
            auxEnemigos = auxEnemigos->siguiente;
        }
    }
}
void eliminarDeCola (int validos)
{
    ColaDeTurnos = borrarNodoPrimeroSimple(ColaDeTurnos);
    for (int i = 0;i<validos;i++)
    {
        if (turnosGuardados [i] < 0)
        {
            ColaDeTurnos = borrarNodoSimple(ColaDeTurnos,i);
        }
    }
}
void restaurarTiempo (nodoPer *aliados, nodoPer * enemigos)
{
    while ((aliados->chara.turno !=ColaDeTurnos->dato)&&(aliados != NULL))
    {
        aliados = aliados->siguiente;
    }
    if (aliados == NULL)
    {
        while ((enemigos->chara.turno != ColaDeTurnos->dato)&&(enemigos != NULL))
        {
            enemigos = enemigos ->siguiente;
        }
        turnosGuardados[ColaDeTurnos->dato] = 100 - enemigos->chara.agilidad;
    }
    else
    {
        turnosGuardados[ColaDeTurnos->dato] = 100 - aliados ->chara.agilidad;
    }

}
void iniciarCombate (nodoPer ** aliados,nodoPer ** enemigos,int validos)
{
    int vivos = 1;
    int i=0;
    int deQuienEs;
    nodo * nuevoNodoSimple;
    while (vivos)
    {
        for (int i=0;i<validos;i++)
        {
                if (turnosGuardados[i] >0)
            {
                turnosGuardados[i] --;
            }
            else if (turnosGuardados[i] == 0)
            {
                nuevoNodoSimple = crearNodoSimple(i);
                ColaDeTurnos = agregarFinalSimple(ColaDeTurnos,nuevoNodoSimple);
            }
            else
            {

            }
            i++;
            if (ColaDeTurnos != NULL)
            {
                /// EN la versión final, esto tiene que realizarse en un hilo aparte.
                restaurarTiempo(*aliados,*enemigos);
                brindarTurnos(*aliados,*enemigos);
                determinarSiSiguenVivos (*aliados,*enemigos,validos);
                eliminarDeCola (validos);
            }
        }

    }
}


/// PREGUNTAR como realizar los turnos (?)
/** Primero tenemos que volver a pensar en como se debe realizar esto. Primero se hacía con una lista y un arreglo dinámico. La lista
guardaba los turnos y trabajaba como una cola, mientras que el arreglo guardaba una referencia al turno y esas cosas.

También tengo que modificar las estructuras para poder designarle a cada uno de los bichos un identificador.*/
