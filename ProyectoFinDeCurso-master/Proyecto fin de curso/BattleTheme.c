#include "BattleTheme.h"
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



/// PREGUNTAR como realizar los turnos (?)
