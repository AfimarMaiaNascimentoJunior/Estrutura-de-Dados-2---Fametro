
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int main() {
    Produto *catalogo = NULL;
    char comando[20];

    printf("=== Controle de Estoque ===\n");

    while (1) {
        printf("\nComando> ");
        if (scanf("%19s", comando) != 1) break;

        if (strcmp(comando, "ADD") == 0) {
            Produto novo;
            scanf("%15s", novo.codigo);
            getchar();
            scanf(" \"%63[^"]\" %d %f", novo.nome, &novo.qtd, &novo.preco);
            catalogo = inserirOrdenado(catalogo, novo);
        } else if (strcmp(comando, "UPD") == 0) {
            char cod[16]; int delta;
            scanf("%15s %d", cod, &delta);
            catalogo = alterarQuantidade(catalogo, cod, delta);
        } else if (strcmp(comando, "DEL") == 0) {
            char cod[16];
            scanf("%15s", cod);
            catalogo = excluirProduto(catalogo, cod);
        } else if (strcmp(comando, "FIND") == 0) {
            char cod[16];
            scanf("%15s", cod);
            Produto *p = localizar(catalogo, cod);
            if (p) printf("Encontrado: %s (%s) qtd=%d preco=%.2f\n", p->codigo, p->nome, p->qtd, p->preco);
            else printf("Produto nao encontrado.\n");
        } else if (strcmp(comando, "LIST") == 0) {
            exibirLista(catalogo);
        } else if (strcmp(comando, "REL") == 0) {
            int itens = 0; float total = 0; Produto *maior = NULL;
            for (Produto *aux = catalogo; aux; aux = aux->prox) {
                itens++;
                total += aux->qtd * aux->preco;
                if (!maior || aux->qtd*aux->preco > maior->qtd*maior->preco) maior = aux;
            }
            printf("Itens distintos: %d\nValor total: %.2f\n", itens, total);
            if (maior) printf("Maior valor: %s (%s) = %.2f\n", maior->codigo, maior->nome, maior->qtd*maior->preco);
        } else if (strcmp(comando, "EXIT") == 0) {
            catalogo = destruirLista(catalogo);
            break;
        } else {
            printf("Comando invalido.\n");
        }
    }
    return 0;
}
