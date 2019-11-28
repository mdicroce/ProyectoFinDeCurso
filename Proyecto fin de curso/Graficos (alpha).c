#include "Graficos (alpha).h"

void graficas (nodoPer * aliados, nodoPer * enemigos)
{
    nodoPer *auxAliados=aliados,*auxEnemigos=enemigos;
    int x,y=1;
     while (auxEnemigos != NULL)
    {
        color(12);
        gotoxy(50,y*4);
        if (auxAliados->chara.turn == 1)
        color(192);
        printf("Nombre: %s",auxEnemigos->chara.nombre);
        color(12);
        gotoxy(50,(y*4)+1);
        if (auxAliados->chara.turn == 1)
        color(192);
        printf("Vida: %i|",auxEnemigos->chara.vida,auxAliados->chara.vidaMax);
        color(12);
        gotoxy(50,(y*4)+2);
        if (auxAliados->chara.turn == 1)
        color(192);
        printf("Tipo: %s",auxEnemigos->chara.clase);
        color(12);
        y++;
        auxEnemigos = auxEnemigos->siguiente;
    }
    y = 1;
    while (auxAliados!= NULL)
    {
        color(10);
        gotoxy(3,y*4);
        if (auxAliados->chara.turn == 1)
        {
            color(32);
        }
        printf("Nombre: %s",auxAliados->chara.nombre);
        color(10);
        gotoxy(3,(y*4)+1);
        if (auxAliados->chara.turn == 1)
        {
            color(32);
        }
        printf("Vida: %i|",auxAliados->chara.vida,auxAliados->chara.vidaMax);
        color(10);
        gotoxy(3,(y*4)+2);
        if (auxAliados->chara.turn == 1)
        {
            color(32);
        }
        printf("Tipo: %s",auxAliados->chara.clase);
        color(10);
        y++;
        auxAliados = auxAliados->siguiente;
    }

}
void menu (int opcion)
{
    int y = 1;
    gotoxy(80,6);
    color(15);
    if (opcion == 0)
        color(240);
    printf("Atacar");
    gotoxy(80,7);
    color(15);
    if (opcion == 1)
    {
        color (240);
    }
    printf("Defender");
    gotoxy(80,8);
    color(15);
    if (opcion == 2)
    {
        color(240);
    }
    printf("Usar Magia");
    gotoxy(80,9);
    color(15);
    if (opcion == 3)
    {
        color (240);
    }
    printf("Usar Objeto");
}
void graficosInicio (void)
{
    system("cls");
    printf(" --------------------------------------------------------- \n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                  Iniciar Partida                        |\n");
    printf("|                  Presione Enter                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf(" --------------------------------------------------------- \n");
    system("pause");

}
void instrucciones (void)
{
    system("cls");
    printf("             Este juego est� presentado como un juego simple de RPG. \n");
    printf("           en cada partida, los heroes ser�n generados autom�ticamente\n");
    printf("       y para hacer funcionar el programa, se le tiene que ingresar un Nombre\n");
    printf("                         a cada uno de estos personajes.\n");
    printf("     Luego los enemigos se generar�n autom�ticamente. Se puede atacar, defender\n");
    printf("         usar magias u objetos. Las opciones se eligen con los botones de \n");
    printf("                   ARRIBA y ABAJO y el ENTER selecciona la opci�n\n");
    printf("                    El juego terminar� cuando los heroes mueran\n");
    system("pause");
}
void graff (void)
{
    printf("  ---------------------------------------------------------\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("  ---------------------------------------------------------\n");
}


/** A VER: Como se tiene que lograr esto: Primero se tiene leer los aliados y enemigos, los aliados van a la derecha, se muestra
la vida, el tipo de soldado y su nombre

Por el otro lado est� los enemigos, que est�n a la derecha que muestran el nombre, la vida restante y el tipo.

Cuando uno de los bichos sea seleccionado, este tiene que cambiar de color. Se crea un menu de dialogo debajo del campo que se despliega, tiene
que contener el nombre del personaje y las acciones que pueda realizar. Una vez seleccionada las acciones se debe determinar a quien
se le va a seleccionar. Por �ltimo se ataca y listo*/
