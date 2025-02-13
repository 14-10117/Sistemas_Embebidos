#include <stdio.h>
#include <stdlib.h>
#include "structura.h"
#define tamaño_maxc 10

struct NODOc
{
    enum Pines_GPIO *Pinc;
    int cabezac;
    int colac;
    int tamañoc;
};


    // Inicializa una cola

    struct NODOc* nuevaColac()
{
    struct NODOc *colac = NULL;
    colac = (struct NODOc*)malloc(sizeof(struct NODOc));
 
    colac->Pinc = (enum Pines_GPIO*)malloc(tamaño_maxc * sizeof(enum Pines_GPIO));
    colac->cabezac = 0;
    colac->colac = -1;
    colac->tamañoc = 0;
 
    return colac;
}

// Tamaño de la cola

int tamañoc(struct NODOc *colac) 
{
    return colac->tamañoc;
}

// Verifica si la cola está vacia

int is_emptyc(struct NODOc *colac) 
{
    if (colac->cabezac == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}
 
// Observa el primer elemento de la cola

int peek_itemc(struct NODOc *colac)
{
    if (is_emptyc(colac))
    {
        printf("La cola está vacia");
    }
 
    return colac->Pinc[colac->cabezac];
}

// Agrega un elemento a la cola

void push_itemc(struct NODOc *colac, int x)
{
    if (tamañoc(colac) == tamaño_maxc)
    {
        printf("La cola está llena");
    }
 
    colac -> colac = (colac -> colac + 1) % tamaño_maxc; 
    colac -> Pinc[colac -> colac] = x;
    colac -> tamañoc++;
}

// Quita elemento de la cola

void pop_itemc(struct NODOc *colac)
{
    if (is_emptyc(colac))
    {
        printf("La cola está vacia");
    }
    colac -> cabezac = (colac->cabezac + 1) % tamaño_maxc;  // queue circular
    colac -> tamañoc--;
}

