#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "queue_linear.h"
//#include "queue_circular.h"
//#include "structura.h"

int main(void)
{       
    struct NODO* colal = nuevaColal();

    if(colal -> Acelerometro->Device->Gravity_size_definition == 00)
    {
        printf("El tamaño de pantalla necesario es 14 bits");
    }
    else if (colal -> Acelerometro->Device->Gravity_size_definition == 01)
    {
        printf("El tamaño de pantalla necesario es 14 bits");
    }
    else if (colal -> Acelerometro->Device->Gravity_size_definition == 10)
    {
        printf("El tamaño de pantalla necesario es 14 bits");
    }
    else if (colal -> Acelerometro->Device->Gravity_size_definition == 11)
    {
        printf("El tamaño de pantalla necesario es 14 bits");
    }
    
    switch(peek_item(colal))
    {
        case 0xA1:
        printf("Interrupción 1\n");
        break;

        case 0xA2:
        printf("Interrupción 2\n");
        break;

        case 0xA3:
        printf("Interrupción 3\n");
        break;

        case 0xA4:
        printf("Interrupción 4\n");
        break;

    } //printf("hola");

}