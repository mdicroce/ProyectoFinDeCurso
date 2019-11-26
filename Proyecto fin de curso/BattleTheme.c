#include "BattleTheme.h"
int *turnosGuardados;
nodo * ColaDeTurnos;
void prueba (nodoPer *aux)
{
    while (aux!= NULL)
    {
        printf("Nombre : %s\n",aux->chara.nombre);
        aux = aux->siguiente;
    }
}
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
    validos = i+1;
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
int previaCombate(nodoPer* aliados, nodoPer *enemigos)
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
    return validos;
}
void brindarTurnos (nodoPer *aliados,nodo* enemigos)
{
    nodoPer * datoBuscado = NULL;
    nodo* auxiliarColaDeTurnos = ColaDeTurnos;
    nodoPer *auxAliados = aliados, *auxEnemigos = enemigos;
    int deQuienEs;

    if (datoBuscado == NULL)
    {
        datoBuscado = buscarNodo(auxiliarColaDeTurnos->dato,auxAliados);
        if (datoBuscado != NULL)
        {
            seleccionarAccion(&auxAliados,&auxEnemigos,&datoBuscado);
        }
        else
        {
            printf("\n\t\t %i",auxiliarColaDeTurnos->dato);
            datoBuscado = buscarNodo(auxiliarColaDeTurnos->dato,auxEnemigos);
            if (datoBuscado != NULL)
            {
                printf("\t\t\tjesus");
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
    nodoPer * auxAliados = aliados, *auxEnemigos = enemigos;

    while ((auxAliados!= NULL)&&(auxAliados->chara.turno !=ColaDeTurnos->dato))
    {
        auxAliados= auxAliados->siguiente;

    }
    if (auxAliados== NULL)
    {

        while ((auxEnemigos->chara.turno != ColaDeTurnos->dato)&&(auxEnemigos!= NULL))
        {
            auxEnemigos= auxEnemigos->siguiente;
        }
        if (turnosGuardados[ColaDeTurnos->dato] != -1)
        {
            turnosGuardados[ColaDeTurnos->dato] = 100 - auxEnemigos->chara.agilidad;
        }

    }
    else
    {
        if (turnosGuardados[ColaDeTurnos->dato] != -1)
        {
            turnosGuardados[ColaDeTurnos->dato] = 100 - auxAliados->chara.agilidad;
        }
    }

}
void roberto (void)
{
    nodo *aux = ColaDeTurnos;
    while (aux != NULL)
    {
        printf("\nsopapo%i",aux->dato);
        aux = aux ->siguiente;
    }
}
void iniciarCombate (nodoPer * aliados,nodoPer * enemigos,int validos)
{
    int vivos = 1;
    int i=0;
    int deQuienEs;
    nodo * nuevoNodoSimple;
    nodoPer * aux = enemigos;
    while (vivos)
    {
        if (aliados == NULL)
        {
            system("cls");
            printf("HOLA");
        }
        for (int i=0;i<validos;i++)
        {
            //printf("\n|%i| %i |",turnosGuardados[i],i);

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
            if (ColaDeTurnos != NULL)
            {
                roberto ();
                /// EN la versión final, esto tiene que realizarse en un hilo aparte.
                determinarSiSiguenVivos (aliados,enemigos,validos);
                restaurarTiempo(aliados,enemigos);
                printf("\n1");
                brindarTurnos(aliados,enemigos); //CORREGIR ATAQUE
                aliados = eliminarEnemigo(aliados);
                printf("\n2");
                enemigos = eliminarEnemigo(enemigos);
                printf("\n3");
                determinarSiSiguenVivos (aliados,enemigos,validos);
                printf("\n4");
                printf("hola");
                eliminarDeCola (validos);
                printf("\n5");
            }
        }
        if ((aliados == NULL) || (enemigos == NULL))
        {
            vivos = 0;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t GAME OVER");
        }
        //Sleep(500);
    }
}

///EL PROBLEMA A RESOLVER es determinar si siguen vivos, porque debería decir que X esta muerto y hacer que su numero se vuelva -1 y no lo hace
/// PREGUNTAR como realizar los turnos (?)
/** Primero tenemos que volver a pensar en como se debe realizar esto. Primero se hacía con una lista y un arreglo dinámico. La lista
guardaba los turnos y trabajaba como una cola, mientras que el arreglo guardaba una referencia al turno y esas cosas.

También tengo que modificar las estructuras para poder designarle a cada uno de los bichos un identificador.*/
