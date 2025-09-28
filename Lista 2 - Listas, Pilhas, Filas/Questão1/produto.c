
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

static Produto* novoProduto(Produto p) {
    Produto *n = malloc(sizeof(Produto));
    if (!n) return NULL;
    *n = p;
    n->prox = NULL;
    return n;
}

Produto* inserirOrdenado(Produto *L, Produto p) {
    Produto *ant=NULL, *cur=L;
    while(cur && strcmp(cur->codigo,p.codigo)<0) {
        ant=cur; cur=cur->prox;
    }
    if (cur && strcmp(cur->codigo,p.codigo)==0) {
        cur->qtd += p.qtd;
        cur->preco = p.preco;
        return L;
    }
    Produto *n=novoProduto(p);
    if (!ant) { n->prox=L; return n; }
    ant->prox=n; n->prox=cur;
    return L;
}

Produto* excluirProduto(Produto *L, const char *codigo) {
    Produto *ant=NULL,*cur=L;
    while(cur && strcmp(cur->codigo,codigo)!=0){ant=cur;cur=cur->prox;}
    if(!cur) return L;
    if(!ant) L=cur->prox; else ant->prox=cur->prox;
    free(cur); return L;
}

Produto* alterarQuantidade(Produto *L, const char *codigo, int delta) {
    Produto *p=localizar(L,codigo);
    if(p) {
        if(p->qtd+delta>=0) p->qtd+=delta;
        else printf("Quantidade negativa nao permitida.\n");
    }
    return L;
}

Produto* localizar(Produto *L, const char *codigo) {
    for(Produto*aux=L;aux;aux=aux->prox) if(strcmp(aux->codigo,codigo)==0) return aux;
    return NULL;
}

void exibirLista(Produto *L) {
    for(Produto*aux=L;aux;aux=aux->prox)
        printf("[%s] %s qtd=%d preco=%.2f\n",aux->codigo,aux->nome,aux->qtd,aux->preco);
}

Produto* destruirLista(Produto *L) {
    while(L){Produto*tmp=L;L=L->prox;free(tmp);} return NULL;
}
