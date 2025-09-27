#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estoque.h"

static void strip(char *s) {
    char *p = s;
    while (*p && isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p)+1);
    int n = strlen(s);
    while (n > 0 && isspace((unsigned char)s[n-1])) {
        s[n-1] = 0; n--;
    }
}

int main() {
    Item *lista = NULL;
    char linha[256];

    puts("=== Sistema de Estoque ===");
    puts("Comandos: ADD, UPD, DEL, FIND, LIST, REL, EXIT");

    while (1) {
        printf(">> ");
        if (!fgets(linha, sizeof(linha), stdin)) break;
        strip(linha);
        if (!*linha) continue;

        if (strncmp(linha, "EXIT", 4) == 0) {
            lista = destruir_lista(lista);
            break;
        } else if (strncmp(linha, "LIST", 4) == 0) {
            imprimir_lista(lista);
        } else if (strncmp(linha, "REL", 3) == 0) {
            gerar_relatorio(lista);
        } else if (strncmp(linha, "ADD", 3) == 0) {
            Item novo;
            char nome[64];
            if (sscanf(linha+3, "%15s "%63[^"]" %d %f",
                       novo.cod, nome, &novo.quantidade, &novo.valor) == 4) {
                strncpy(novo.descricao, nome, sizeof(novo.descricao));
                lista = inserir_ordenado(lista, novo);
                puts("Produto adicionado/atualizado.");
            } else {
                puts("Formato inválido. Use: ADD COD "nome" qtd preco");
            }
        } else if (strncmp(linha, "DEL", 3) == 0) {
            char cod[16];
            if (sscanf(linha+3, "%15s", cod) == 1) {
                lista = excluir_por_codigo(lista, cod);
                puts("Produto removido (se existia).");
            }
        } else if (strncmp(linha, "FIND", 4) == 0) {
            char cod[16];
            if (sscanf(linha+4, "%15s", cod) == 1) {
                Item *p = localizar(lista, cod);
                if (p)
                    printf("Encontrado: %s - %s (qtd=%d, valor=%.2f)\n",
                           p->cod, p->descricao, p->quantidade, p->valor);
                else puts("Produto não localizado.");
            }
        } else if (strncmp(linha, "UPD", 3) == 0) {
            char cod[16]; int delta;
            if (sscanf(linha+3, "%15s %d", cod, &delta) == 2) {
                lista = alterar_quantidade(lista, cod, delta);
                puts("Quantidade alterada (se possível).");
            }
        } else {
            puts("Comando desconhecido.");
        }
    }
    puts("Encerrando sistema...");
    return 0;
}