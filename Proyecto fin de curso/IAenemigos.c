#include "IAenemigos.h"

IA (nodoPer *aliados,nodoPer *enemigos, nodoPer**seleccionado)
{
    int prob = rand () %100;
    prob = 15;
    nodoPer *auxAliados = aliados, *auxEnemigos = enemigos, *auxiliar= NULL;
    system("cls");
    printf("\n\n HOLA");
    printf("    %i",(*seleccionado)->chara.tipo);
    system("pause");
    switch ((*seleccionado)->chara.tipo)
    {
    case 4: ///tanque ataca al azar, con mayores posibilidades al rougue y al soldado
        printf("hola");
        for (prob;prob>0;prob--)
        {
            if (auxAliados -> siguiente != NULL)
            {
                auxAliados = auxAliados -> siguiente;
            }
            else
            {
                auxAliados = aliados;
            }
            printf("jelou");
        }
        auxAliados = calculoAtaque(*seleccionado,auxAliados);
        break;
    case 5:///normal ataca al azar, con mayores posibilidades al mago y curador
        printf("hola2");
        for (prob;prob>0;prob--)
        {
            if (auxAliados -> siguiente != NULL)
            {
                auxAliados = auxAliados -> siguiente;
            }
            else
            {
                auxAliados = aliados;
            }
            printf("jelou");
        }
        auxAliados = calculoAtaque(*seleccionado,auxAliados);
        break;
    case 6:///mago si tiene poca vida alguno, cura. Luego, por una cuesti�n aleatoria,
        printf("hola3");
        while (auxEnemigos != NULL)
        {
            if (auxEnemigos->chara.vida < (auxEnemigos->chara.vidaMax / 2))
            {
                if (auxiliar == NULL)
                {
                    auxiliar = auxEnemigos;
                }
                else if ((auxiliar->chara.vida/auxiliar->chara.vidaMax)>(auxEnemigos->chara.vida/auxEnemigos->chara.vidaMax))
                {
                    auxiliar = auxEnemigos;
                }
            }
            auxEnemigos = auxEnemigos -> siguiente;
        }
        if (auxiliar != NULL)
        {
            curacion(*seleccionado,auxiliar);
        }
        else
        {
            for (int i = 0; i<(prob/5);i++)
            {
                if (auxEnemigos == NULL)
                {
                    auxEnemigos = enemigos;
                }
                else
                {
                    auxEnemigos = auxEnemigos->siguiente;
                }
            }
            if (auxEnemigos != NULL)
            {
                auxEnemigos = buffDamage(seleccionado,auxEnemigos);
            }
        }
        break;
    default:
        break;
    }
}

/** Primero, necesit que lea que tipo de bicho es. Luego, dependiendo del tipo de bicho lea la situaci�n del campo.
luego quiero que realice  su acci�n (sea atacar, defender, curar o buffear) dependiendo de la situaci�n. */
