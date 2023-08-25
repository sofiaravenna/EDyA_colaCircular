//
// Created by Ciro on 20/8/2023.
//

#include "colaCircular.h"
#include <stdlib.h>
#include <stdio.h>

int desencolar(Cola * cola) {
    if(cola->tamanio == 0){
        printf("La cola esta vacia.\n");
        return (-1);
    }
    int num= cola->cola[cola->posicionDeExtraccion];
    cola->cola[cola->posicionDeExtraccion]=-100;
    cola->posicionDeExtraccion= siguientePosicion(cola,cola->posicionDeExtraccion);
    cola->tamanio--;
    return num;
}

void imprimir(Cola *cola) {
    if(cola->tamanio == 0){
        printf("La cola esta vacia.\n");
    }else{
        int i = cola->posicionDeExtraccion;
        int cont=0;
        while(cont<cola->tamanio){
            printf("%d\t",cola->cola[i]);
            i= (i+1)% cola->capacidad;
            cont++;
        }
        printf("\t");
    }
    printf("\n");
}

void intercambiarValores(Cola *cola, int posicionEnLaCola, int posicionesHaciaAdelante) {
    if(cola->tamanio<2){
        printf("La cola tiene que tener por lo menos dos elementos.\n");
        return;
    }
    int cont=0;
    int pos= posicionEnLaCola;
    while (cont != posicionesHaciaAdelante){
        pos= siguientePosicion(cola,posicionEnLaCola);
        cont++;
    }
    int temp= cola->cola[pos];
    cola->cola[pos] =cola->cola[posicionEnLaCola];
    cola->cola[posicionEnLaCola]=temp;
}

Cola * newCola(int capacidad) {
    Cola * aux = NULL;

    aux = malloc(sizeof(Cola));

    if (aux == NULL) {
        printf("No se pudo reservar memoria para la cola.\n");
        exit(-1);
    }

    aux->cola = malloc(sizeof(int) * capacidad);
    aux->capacidad = capacidad;
    aux->tamanio = 0;
    aux->posicionDeExtraccion = 0;
    aux->posicionDeInsersion = 0;

    return aux;
}

void encolar(Cola *cola, int elemento) {
    if ( llena(cola) ) {
        printf("La cola esta llena.\n");
        return;
    }

    cola->cola[cola->posicionDeInsersion] = elemento;
    cola->posicionDeInsersion = siguientePosicion(cola, cola->posicionDeInsersion);
    cola->tamanio++;
}

int llena(Cola *cola) {
    return siguientePosicion(cola, cola->posicionDeInsersion) == cola->posicionDeExtraccion;
}

int siguientePosicion(Cola *cola, int posicion) {
    return ++posicion % cola->capacidad;
}