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

void seleccionarAccion (nodoPer * aliado)
{

}
