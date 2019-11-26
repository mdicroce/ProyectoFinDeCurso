#include "MenuDeAccion.h"

/**imaginemos como se tiene que comportar esto: primero abre el menu, con 4 opciones: atacar, defender, habilidad y curacion.

Luego, dependiendo del tipo de personaje desplega más menues o no. Estos "más menues" tiene que estar guardados
en algún lugar. Una estructura que guarde un menu para cada tipo de soldado con todas las opciones?

Select: 0-3
Pero si es un soldado no tendria la entrada a 2. ¿Como la bloqueo, o directamente la elimino sin que afecte al resto?
Primero lee el tipo de personaje que es el seleccionado por referencia. Esto abre un menu para cada uno?

Si x es soldado, entonces la opción 2 está bloqueada y se le suma automaticamente 1 o se le resta 1.

Segundo, cada una de esas opciones te dirige a una nueva opcion, en el caso de ataque, te pide que selecciones un enemigo.

Estos enemigos se seleccionan directamente de la lista y cuando se elimina un enemigo directamente dej de poder seleccionarse.

Por último se debe re - aceptar

En el caso de las magias de buff o curación, se seleccionan los aliados. Por último se aceptaría.

La defenza directamente se tiene que aceptar.

los objetos se veran despues.*/

nodoPer * seleccionarAtacante (nodoPer * enemigos)
{
    int flag = 1;
    nodoPer * aux = enemigos;
    char opc;
    while (flag)
    {
        fflush(stdin);
        system("cls");
        printf("%s",aux->chara.nombre);
        opc = getch();
        switch (opc)
        {
        case 72:
            if (aux ->anterior != NULL)
            {
                aux = aux->anterior;
            }
            break;
        case 80:
            if (aux ->siguiente != NULL)
            {
                aux = aux ->siguiente;
            }
            break;
        case 13:
            flag = 0;
            break;
        default:
            break;
        }
    }
    return aux;
}
void seleccionarAccion (nodoPer ** aliado,nodoPer ** enemigos, nodoPer **persona)
{
    nodoPer * objetivo;
    nodoPer *aux = (*enemigos);
    if ((*persona)->chara.mod == 1)
    {
        (*persona )= defenzaOF((*persona));
    }
    int seleccion = 0,seleccionAuxiliar;
    int flag = 1;
    int flag2 = 1;
    int i =0;
    char boton;
    while (flag)
    {
        while (flag2)
        {

            fflush(stdin);
            printf("%i",seleccion);
            boton = getch();
            switch (boton)
            {
            case 72:
                printf("arriba");
                if (seleccion > 0)
                {
                    seleccion--;
                }
                break;
            case 80:
                printf("abajo");
                if (seleccion < 3)
                {
                    seleccion++;
                }
                break;
            case 13:
                flag2 =0;
            break;
            default:
            break;
            }
        }
        fflush(stdin);
        switch (seleccion)
        {
        case 0: ///ataque
            objetivo = seleccionarAtacante (*enemigos);
            printf("anterior %i\n",objetivo->chara.vida);
            objetivo = calculoAtaque((*persona),objetivo);
            printf("depuis%i",objetivo->chara.vida);
            system("pause");
            printf("\t\tEste es el nombre %s",aux->chara.nombre);
            if ((*persona)->chara.mod == 2)
            {
                (*persona) = debuffDamagge((*persona));
            }
            flag = 0;
            break;
        case 1:///defenza
            (*persona)=defenzaON((*persona));
            flag = 0;
            break;
        case 2:///magia
            flag = 0;
            if ((*persona)->chara.tipo == 0)
            {

            }
            else if ((*persona)->chara.tipo == 1)
            {
                //seleccionAuxiliar=seleccionarMagia ();
                if (seleccionAuxiliar == 0)
                {
                    objetivo = seleccionarAtacante((*aliado));
                    objetivo = curacion((*persona),objetivo);
                }
                else
                {

                }
            }
            else
            {
                flag = 1;
            }

            break;
        case 3:///items
            flag = 0;
            break;
        default:
            break;
        }
    }
}
