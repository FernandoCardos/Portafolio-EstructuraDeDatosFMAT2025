#ifndef PILA_H
#define PILA_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Pila;

void inicializarPila(Pila *p);
int estaVacia(Pila *p);
void push(Pila *p, int valor);
int pop(Pila *p);
int peek(Pila *p);

#endif // PILA_H