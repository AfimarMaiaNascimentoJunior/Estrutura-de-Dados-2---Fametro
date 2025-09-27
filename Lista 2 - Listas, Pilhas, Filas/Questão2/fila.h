
#ifndef FILA_H
#define FILA_H
#include <stdbool.h>

typedef struct Cliente{
    char id[24];
    int qtd;
    struct Cliente *prox;
} Cliente;

typedef struct {
    Cliente *ini,*fim;
} Fila;

void inicializarFila(Fila*);
void enfileirar(Fila*,Cliente);
bool desenfileirar(Fila*,Cliente*);
bool filaVazia(Fila*);
void limparFila(Fila*);

#endif
