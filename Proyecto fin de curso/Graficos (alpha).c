#include "Graficos (alpha).h"

void graficas (void)
{
    int i = 0;
    //printf("hola puto");
    int x,y;
    x = whereX();
    y = whereY();
    for (x;x<100;x++)
    {
        gotoxy(x,x);
        printf("%i",i);
        i++;
    }

}
/** A VER: Como se tiene que lograr esto: Primero se tiene leer los aliados y enemigos, los aliados van a la derecha, se muestra
la vida, el tipo de soldado y su nombre

Por el otro lado está los enemigos, que están a la derecha que muestran el nombre, la vida restante y el tipo.

Cuando uno de los bichos sea seleccionado, este tiene que cambiar de color. Se crea un menu de dialogo debajo del campo que se despliega, tiene
que contener el nombre del personaje y las acciones que pueda realizar. Una vez seleccionada las acciones se debe determinar a quien
se le va a seleccionar. Por último se ataca y listo*/
