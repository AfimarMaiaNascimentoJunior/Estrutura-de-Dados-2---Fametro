#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

static Produto* criar(const Produto *ref) {
    Produto *p = malloc(sizeof(Produto));
    if (!p) return NULL;
    strncpy(p->codigo, ref->codigo, sizeof(p->codigo));
    strncpy(p->nome, ref->nome, sizeof(p->nome));
    p->qtd = ref->qtd;
    p->preco = ref->preco;
    p->prox = NULL;
    return p;
}

Produto* inserir_inicio(Produto *L, Produto p) {
    Produto *novo = criar(&p);
    if (!novo) return L;
    novo->prox = L;
    return novo;
}

Produto* inserir_ordenado_por_codigo(Produto *L, Produto p) {
    Produto *ant = NULL, *at = L;
    while (at && strcmp(at->codigo, p.codigo) < 0) {
        ant = at;
        at = at->prox;
    }
    if (at && strcmp(at->codigo, p.codigo) == 0) {
        at->qtd += p.qtd;
        at->preco = p.preco;
        return L;
    }
    Produto *novo = criar(&p);
    if (!novo) return L;
    if (!ant) {
        novo->prox = L;
        return novo;
    } else {
        ant->prox = novo;
        novo->prox = at;
        return L;
    }
}

Produto* remover_por_codigo(Produto *L, const char *codigo) {
    Produto *ant = NULL, *at = L;
    while (at && strcmp(at->codigo, codigo) != 0) {
        ant = at;
        at = at->prox;
    }
    if (!at) return L;
    if (!ant) L = at->prox;
    else ant->prox = at->prox;
    free(at);
    return L;
}

Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd) {
    for (Produto *p = L; p; p = p->prox) {
        if (strcmp(p->codigo, codigo) == 0) {
            if (p->qtd + delta_qtd >= 0)
                p->qtd += delta_qtd;
            return L;
        }
    }
    return L;
}

Produto* buscar(Produto *L, const char *codigo) {
    for (Produto *p = L; p; p = p->prox) {
        if (strcmp(p->codigo, codigo) == 0) return p;
    }
    return NULL;
}

void listar(Produto *L) {
    if (!L) {
        printf("[Lista vazia]\n");
        return;
    }
    printf("%-10s %-20s %-10s %-10s\n", "Código", "Nome", "Qtd", "Preço");
    for (Produto *p = L; p; p = p->prox) {
        printf("%-10s %-20s %-10d %-10.2f\n", p->codigo, p->nome, p->qtd, p->preco);
    }
}

Produto* limpar(Produto *L) {
    while (L) {
        Produto *tmp = L->prox;
        free(L);
        L = tmp;
    }
    return NULL;
}

void relatorio(Produto *L) {
    int distintos = 0;
    double total = 0.0;
    Produto *top = NULL;
    for (Produto *p = L; p; p = p->prox) {
        distintos++;
        double parcial = p->qtd * p->preco;
        total += parcial;
        if (!top || parcial > top->qtd * top->preco)
            top = p;
    }
    printf("Itens distintos: %d\n", distintos);
    printf("Valor total: %.2f\n", total);
    if (top) {
        printf("Maior imobilizado: %s (%s) qtd=%d preco=%.2f total=%.2f\n",
               top->codigo, top->nome, top->qtd, top->preco, top->qtd*top->preco);
    }
}