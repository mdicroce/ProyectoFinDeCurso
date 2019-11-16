#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "listasDobles.h"
#include "IniciarPersonajes.h"
void turnoPrueba()
{
    printf("puto el que lea");
    int ignacio [10];
    for (int i = 0;i<10;i++)
    {
        ignacio [i] = rand() % 10 + 5;
    }
    while (1)
    {
        for (int i = 0;i<10;i++)
        {
            ignacio [i] --;
            printf("\nignacio %i %i",i,ignacio[i]);
            if (ignacio[i]==0)
            {
                printf("\nIgnacio %i es puto",i);
            }
        }
        Sleep(1000);
        printf("\n");

    }

}

int main()
{
    turnoPrueba();
    return 0;
}
