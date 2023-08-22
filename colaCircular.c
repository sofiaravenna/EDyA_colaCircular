//
// Created by Ciro on 20/8/2023.
//

#include "colaCircular.h"
#include <stdlib.h>
#include <stdio.h>

int desencolar(Cola * cola) {

    return 0;
}


void imprimir(Cola *cola) {
    if(cola->tamanio == 0){
        printf("La cola esta vacia.\n");
    }else{
        int i = cola->posicionDeExtraccion;
        int cont=0;
        while(cont<cola->tamanio){
            printf("%d",cola->cola[i]);
            i= (i+1)% cola->capacidad; //Avanza en un ciclo circular por el arreglo
            cont++;
        }
        printf("\t");
    }
}


void intercambiarValores(Cola *cola, int posicionEnLaCola, int posicionesHaciaAdelante) {
    /** agregar código */
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