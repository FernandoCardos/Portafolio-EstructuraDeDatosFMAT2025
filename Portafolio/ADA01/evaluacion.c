#include "evaluacion.h"
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluarPostfijo(char* postfijo) {
    Pila pilaOperandos;
    inicializarPila(&pilaOperandos);

    char* token = strtok(postfijo, " ");
    while (token != NULL) {
        if (esDigito(token[0])) {
            push(&pilaOperandos, atoi(token));
        } else {
            int operando2 = pop(&pilaOperandos);
            int operando1 = pop(&pilaOperandos);

            switch (token[0]) {
                case '+': push(&pilaOperandos, operando1 + operando2); break;
                case '-': push(&pilaOperandos, operando1 - operando2); break;
                case '*': push(&pilaOperandos, operando1 * operando2); break;
                case '/':
                    if (operando2 == 0) {
                        printf("Error: Division por cero.\n");
                        exit(1);
                    }
                    push(&pilaOperandos, operando1 / operando2);
                    break;
                case '^': {
                    int resultado = 1;
                    for (int i = 0; i < operando2; i++) {
                        resultado *= operando1;
                    }
                    push(&pilaOperandos, resultado);
                    break;
                }
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&pilaOperandos);
}
