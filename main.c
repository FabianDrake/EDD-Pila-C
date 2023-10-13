#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} TipoNodo;

typedef TipoNodo* PunteroNodo;
typedef TipoNodo* Pila;

void apilar(Pila* pila, int valor);
int desapilar(Pila* pila);
void mostrar(Pila* pila);

int main() {
    Pila pila = NULL;

    apilar(&pila, 20); // Primer elemento que será el último
    apilar(&pila, 10);
    apilar(&pila, 40);
    apilar(&pila, 30);
    apilar(&pila, 90); // Último elemento que será el primero
    printf("Contenido de la pila: \n");
    mostrar(&pila);

    printf("\nContenido de la pila con 2 pops: \n");
    desapilar(&pila); // Borramos el elemento en la parte superior
    desapilar(&pila); // Borramos el elemento en la parte superior
    mostrar(&pila);
    
    getchar();
    return 0;
}

void apilar(Pila* pila, int valor) {
    PunteroNodo nuevoNodo = (PunteroNodo)malloc(sizeof(TipoNodo));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}

int desapilar(Pila* pila) {
    PunteroNodo nodoSuperior;
    int valor;

    nodoSuperior = *pila;
    if (!nodoSuperior) {
        return 0; // La pila está vacía
    }

    *pila = nodoSuperior->siguiente;
    valor = nodoSuperior->valor;
    free(nodoSuperior);
    return valor;
}

void mostrar(Pila* pila) {
    PunteroNodo actual = *pila;

    if (*pila == NULL) {
        printf("La pila está vacía.\n");
    } else {
        while (actual != NULL) {
            printf("%d, ", actual->valor);
            actual = actual->siguiente;
        }
    }
}