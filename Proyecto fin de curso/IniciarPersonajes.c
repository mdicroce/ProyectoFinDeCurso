#include "IniciarPersonajes.h"
nodoPer * aliados, *enemigos;
personajes charas[7];
/**TIPOS DE PERSONAJES:
tipo 0 = Mago
tipo 1 = Curador
tipo 2 = Rougue
tipo 3 = Guerrero

TIPOS DE ENEMIGOS:
tipo 4 = tanque
tipo 5 = Normal
tipo 6 = curandero - buffeador*/
personajes  crearPersonajes (personajes characters [])
{
    int i =0,x;

    for (i=0;i<4;i++)
    {
        characters [i].tipo = i;
        characters[i].vida = rand()%15+(30+(i*7));
        characters[i].suerte=rand()%10+5;
        characters[i].lvl = 1;
        characters[i].inteligencia=rand()%6+(15-(i*5));
        characters[i].fuerza=rand ()%11+(5+(3*i));
        characters[i].defenza=rand()%11+(5+i);
        characters[i].agilidad=rand()%11+(10+(5*i));
        if (i == 2)
        {
            characters[i].suerte= characters[i].suerte * 2;
            characters[i].agilidad = characters [i].agilidad *2;
        }
    }
}
personajes  crearEnemigos (personajes enemy[])
{
    int i =4,x;

    for (i=0;i<7;i++)
    {
        enemy [i].tipo = i;
        enemy[i].vida = rand()%26-i*2+(70-i*10);
        enemy[i].suerte=rand()%i+5;
        enemy[i].lvl = 1;
        enemy[i].inteligencia=rand()%6+i;
        enemy[i].fuerza=rand ()%11+(3+(8-i));
        if (i==5)
        {
            enemy[i].fuerza += 3;
        }
        enemy[i].defenza=rand()%6+(15-i);
        enemy[i].agilidad=rand()%20+(5);
    }
}
nodoPer * crearListaEnemigos ()
{

}
nodoPer * crearListaAliados()
{

}
