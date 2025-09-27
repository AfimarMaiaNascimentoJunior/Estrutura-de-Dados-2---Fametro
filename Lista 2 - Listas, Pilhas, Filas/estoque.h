#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct Item {
    char cod[16];
    char descricao[64];
    int quantidade;
    float valor;
    struct Item *prox;
} Item;

Item* adicionar_no_inicio(Item *lista, Item novo);
Item* inserir_ordenado(Item *lista, Item novo);
Item* excluir_por_codigo(Item *lista, const char *cod);
Item* alterar_quantidade(Item *lista, const char *cod, int delta);
Item* localizar(Item *lista, const char *cod);
void imprimir_lista(Item *lista);
Item* destruir_lista(Item *lista);
void gerar_relatorio(Item *lista);

#endif