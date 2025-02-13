#include <stdio.h>
#include <stdlib.h>
#include "structura.h"
#define tamaño_maxl 5


    struct NODO
    {
        enum Pines_GPIO *Pin;
        datos *Acelerometro;
        int cabeza;
        int cola;
        int tamaño;
    };


    // Inicializa una cola

    struct NODO* nuevaColal()
{
    struct NODO *colal = NULL;
    colal = (struct NODO*)malloc(sizeof(struct NODO));
 
    colal -> Pin = (enum Pines_GPIO*)malloc(tamaño_maxl * sizeof(enum Pines_GPIO));
    colal -> Acelerometro = (datos*)malloc(tamaño_maxl * sizeof(datos));
    colal -> cabeza = 0;
    colal -> cola = -1;
    colal -> tamaño = 0;
 
    return colal;
}

// Tamaño de la cola

int tamaño(struct NODO *colal) 
{
    return colal->tamaño;
}

// Verifica si la cola está vacia

int is_empty(struct NODO *colal) 
{
    if (colal->cabeza == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}
 
// Observa el Pin del primer elemento de la cola

enum Pines_GPIO peek_item(struct NODO *colal)
{
    if (is_empty(colal))
    {
        printf("La cola está vacia");
    }
 
    return colal -> Pin[colal->cabeza]; 
}

// Agrega elemento de la cola

void push_item(struct NODO *colal, int x)
{
    if (tamaño(colal) == tamaño_maxl)
    {
        printf("La cola está llena");
    }
 
    colal -> cola = (colal -> cola + 1);    
    colal -> Pin[colal -> cola] = x;
    colal -> tamaño++;
}

// Quita elemento de la cola

void pop_item(struct NODO *colal)
{
    if (is_empty(colal))
    {
        printf("La cola está vacia");
    }
    colal -> cabeza = (colal->cabeza + 1);
    colal -> tamaño--;
}  