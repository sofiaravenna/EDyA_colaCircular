#include <stdio.h>
#include "colaCircular.h"

int main() {
    Cola * cola = newCola(4);

    /** imprime "La cola esta vacia" */
    printf("Desencolar: %d\n", desencolar(cola));
    encolar(cola, 1);
    encolar(cola, 2);
    encolar(cola, 3);

    /** imprime "La cola esta llena" */
    encolar(cola, 4);

    /** imprime 1 2 3 */
    imprimir(cola);

    /** imprime 1 */
    printf("Desencolar: %d\n", desencolar(cola));

    encolar(cola, 4);

    /** imprime 2 */
    printf("Desencolar: %d\n", desencolar(cola));
    /** imprime 3 */
    printf("Desencolar: %d\n", desencolar(cola));


    /** imprime 4 */
    imprimir(cola);

    encolar(cola, 5);
    encolar(cola, 10);


    /** imprime 4 5 10 */
    imprimir(cola);

    intercambiarValores(cola, 1, 2);

    /** imprime 5 4 10 */
    imprimir(cola);

    intercambiarValores(cola, 1, 3);

    /** imprime 5 4 10 */
    imprimir(cola);

    /** imprime 5 */
    printf("Desencolar: %d\n", desencolar(cola));

    /** imprime 4 10 */
    imprimir(cola);
    return 0;
}
