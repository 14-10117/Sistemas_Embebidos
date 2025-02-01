#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Pila{
    int tamaño;
    char datos[];
    int n_elementos;
}pila;