#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

static Item* criar_item(const Item *ref) {
    Item *p = malloc(sizeof(Item));
    if (!p) return NULL;
    strncpy(p->cod, ref->cod, sizeof(p->cod));
    strncpy(p->descricao, ref->descricao, sizeof(p->descricao));
    p->quantidade = ref->quantidade;
    p->valor = ref->valor;
    p->prox = NULL;
    return p;
}

Item* adicionar_no_inicio(Item *lista, Item novo) {
    Item *p = criar_item(&novo);
    if (!p) return lista;
    p->prox = lista;
    return p;
}

Item* inserir_ordenado(Item *lista, Item novo) {
    Item *ant = NULL, *at = lista;
    while (at && strcmp(at->cod, novo.cod) < 0) {
        ant = at;
        at = at->prox;
    }
    if (at && strcmp(at->cod, novo.cod) == 0) {
        at->quantidade += novo.quantidade;
        at->valor = novo.valor;
        return lista;
    }
    Item *p = criar_item(&novo);
    if (!p) return lista;
    if (!ant) {
        p->prox = lista;
        return p;
    } else {
        ant->prox = p;
        p->prox = at;
        return lista;
    }
}

Item* excluir_por_codigo(Item *lista, const char *cod) {
    Item *ant = NULL, *at = lista;
    while (at && strcmp(at->cod, cod) != 0) {
        ant = at;
        at = at->prox;
    }
    if (!at) return lista;
    if (!ant) lista = at->prox;
    else ant->prox = at->prox;
    free(at);
    return lista;
}

Item* alterar_quantidade(Item *lista, const char *cod, int delta) {
    for (Item *p = lista; p; p = p->prox) {
        if (strcmp(p->cod, cod) == 0) {
            if (p->quantidade + delta >= 0)
                p->quantidade += delta;
            return lista;
        }
    }
    return lista;
}

Item* localizar(Item *lista, const char *cod) {
    for (Item *p = lista; p; p = p->prox) {
        if (strcmp(p->cod, cod) == 0) return p;
    }
    return NULL;
}

void imprimir_lista(Item *lista) {
    if (!lista) {
        printf("[Lista vazia]\n");
        return;
    }
    printf("%-10s %-20s %-10s %-10s\n", "Código", "Descrição", "Qtd", "Preço");
    for (Item *p = lista; p; p = p->prox) {
        printf("%-10s %-20s %-10d %-10.2f\n", p->cod, p->descricao, p->quantidade, p->valor);
    }
}

Item* destruir_lista(Item *lista) {
    while (lista) {
        Item *tmp = lista->prox;
        free(lista);
        lista = tmp;
    }
    return NULL;
}

void gerar_relatorio(Item *lista) {
    int total_itens = 0;
    double total_valor = 0.0;
    Item *mais_caro = NULL;
    for (Item *p = lista; p; p = p->prox) {
        total_itens++;
        double parcial = p->quantidade * p->valor;
        total_valor += parcial;
        if (!mais_caro || parcial > mais_caro->quantidade * mais_caro->valor)
            mais_caro = p;
    }
    printf("Resumo do estoque:\n");
    printf("- Produtos distintos: %d\n", total_itens);
    printf("- Valor total: %.2f\n", total_valor);
    if (mais_caro) {
        printf("- Maior imobilizado: %s (%s), qtd=%d, preço=%.2f, total=%.2f\n",
               mais_caro->cod, mais_caro->descricao,
               mais_caro->quantidade, mais_caro->valor,
               mais_caro->quantidade * mais_caro->valor);
    }
}