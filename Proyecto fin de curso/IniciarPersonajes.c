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
        characters [i].vidaMax = characters[i].vida;
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
void  crearEnemigos (personajes enemy[])
{
    int i =4,x;

    for (i=4;i<7;i++)
    {
        enemy [i].tipo = i;
        enemy[i].vida = rand()%26-i*2+(70-i*10);
        enemy [i].vidaMax = enemy[i].vida;
        enemy[i].suerte=rand()%i+5;
        enemy[i].lvl = 1;
        enemy[i].inteligencia=rand()%6+i;
        enemy[i].fuerza=rand ()%11+(3+(8-i));
        enemy[i].fuerzaOrg = enemy [i].fuerza;
        if (i==5)
        {
            enemy[i].fuerza += 3;
        }
        enemy[i].defenza=rand()%6+(15-i);
        enemy[i].agilidad=rand()%20+(5);
    }
}
int seleccionarEnemigosAzar (int x[10])
{
    ///0=normal, 1=tanque, 2=mago
    int validos = rand () %8 + 2;
    int random;
    for (int i=0;0<2;i++)
    {
        x[i]=rand () %2;
    }
    for (int i=2;i<validos;i++)
    {
        random = rand()%100;
        if (random <45)
        {
            x[i]=5;
        }
        else if(random>75)
        {
            x[i]=6;
        }
        else
        {
            x[i]=4;
        }
    }
    return validos;
}
nodoPer * crearListaEnemigos (personajes enemys[])
{
    int objetivo[10];
    int validos;
    nodoPer * finali = inicLista();
    nodoPer * nuevoNodo;
    validos = seleccionarEnemigosAzar(objetivo);
    crearEnemigos(enemys);
    for (int i = 0; i<validos; i++)
    {
        nuevoNodo = crearNodo(enemys [objetivo[i]]);
        finali = agregarPpio(finali,nuevoNodo);
    }
    return finali;
}
nodoPer * crearListaAliados(personajes aliados[])
{
    nodoPer * nuevoNodo;
    nodoPer * finali = inicLista();
    crearPersonajes(aliados);
    for (int i = 0; i<4;i++)
    {
        nuevoNodo = crearNodo(aliados[i]);
        finali = agregarPpio(finali,nuevoNodo);
    }
    return finali;
}
