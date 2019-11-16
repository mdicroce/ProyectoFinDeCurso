#include "BattleTheme.h"
int turnos [30];
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

brindarTurno (nodoPer *aliados, nodoPer * enemigos)
{

}
