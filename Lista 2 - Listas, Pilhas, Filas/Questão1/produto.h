
#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto {
    char codigo[16];
    char nome[64];
    int qtd;
    float preco;
    struct Produto *prox;
} Produto;

Produto* inserirOrdenado(Produto *L, Produto p);
Produto* excluirProduto(Produto *L, const char *codigo);
Produto* alterarQuantidade(Produto *L, const char *codigo, int delta);
Produto* localizar(Produto *L, const char *codigo);
void exibirLista(Produto *L);
Produto* destruirLista(Produto *L);

#endif
