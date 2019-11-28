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
    if (danio <= 0)
    {
        defensor->chara.vida--;
    }
    else
    {
        defensor->chara.vida -= danio;
    }

    return defensor;
}

nodoPer * eliminarEnemigo (nodoPer * aliados)
{
    personajes auxiliares[20];
    int i=0,validos;
    nodoPer*aux = aliados;
    while (aux != NULL)
    {
        auxiliares[i] = aux->chara;
        i++;
        aux = aux ->siguiente;
    }
    validos = i;
    for (i=0;i<validos;i++)
    {
        if (auxiliares[i].vida <= 0)
        {
            aliados = borrarNodo(aliados,auxiliares[i]);
        }
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

nodoPer * brindarTurnos(nodoPer * aliados,nodoPer *enemigos)
{
    nodoPer *auxAliados,*auxEnemigos;
    while ((aliados != NULL) && (enemigos != NULL))
    {
        auxAliados = aliados;
        auxEnemigos = enemigos;
        while ((auxAliados!= NULL)&&(enemigos != NULL))
        {
            auxAliados->chara.tiempo --;
            if (auxAliados->chara.tiempo == 0)
            {
                auxAliados->chara.turn = 1;
                system("cls");
                graficas(aliados,enemigos);
                seleccionarAccion(&aliados,&enemigos,&auxAliados);
                auxAliados->chara.turn = 0;
                auxAliados->chara.tiempo = 100 - auxAliados->chara.agilidad;
                enemigos = eliminarEnemigo(enemigos);
            }
            auxAliados = auxAliados ->siguiente;
        }
        auxEnemigos = enemigos;
        while ((auxEnemigos != NULL)&&(aliados != NULL))
        {
            auxAliados = aliados;
            auxEnemigos->chara.tiempo --;
            if (auxEnemigos->chara.tiempo==0)
            {
                auxEnemigos->chara.turn = 1;
                system("cls");
                graficas(aliados,enemigos);
                IA (aliados,enemigos,&auxEnemigos);
                auxEnemigos->chara.turn =0;
                auxEnemigos->chara.tiempo = 100 - auxEnemigos->chara.agilidad;
                aliados = eliminarEnemigo(aliados);
            }
            auxEnemigos = auxEnemigos->siguiente;
        }
    }
    system("cls");
    printf("GAME OVER\n\n\n");
    system("pause");
    return aliados;
}
///EL PROBLEMA A RESOLVER es determinar si siguen vivos, porque debería decir que X esta muerto y hacer que su numero se vuelva -1 y no lo hace
/// PREGUNTAR como realizar los turnos (?)
/** Primero tenemos que volver a pensar en como se debe realizar esto. Primero se hacía con una lista y un arreglo dinámico. La lista
guardaba los turnos y trabajaba como una cola, mientras que el arreglo guardaba una referencia al turno y esas cosas.

También tengo que modificar las estructuras para poder designarle a cada uno de los bichos un identificador.*/
