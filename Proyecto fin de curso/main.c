#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"


int main()
{
    srand(time(NULL));
    int i;
    while (1)
    {
        i = rand();
        printf("\t%i",rand()%(11+(10*2))+0);
    }
    return 0;
}
