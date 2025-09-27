#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produto.h"

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
    Produto *lista = NULL;
    char linha[256];

    puts("=== Estoque ===");
    puts("Comandos: ADD, UPD, DEL, FIND, LIST, REL, EXIT");

    while (1) {
        printf(">> ");
        if (!fgets(linha, sizeof(linha), stdin)) break;
        strip(linha);
        if (!*linha) continue;

        if (strncmp(linha, "EXIT", 4) == 0) {
            lista = limpar(lista);
            break;
        } else if (strncmp(linha, "LIST", 4) == 0) {
            listar(lista);
        } else if (strncmp(linha, "REL", 3) == 0) {
            relatorio(lista);
        } else if (strncmp(linha, "ADD", 3) == 0) {
            Produto novo;
            char nome[64];
            if (sscanf(linha+3, "%15s "%63[^"]" %d %f",
                       novo.codigo, nome, &novo.qtd, &novo.preco) == 4) {
                strncpy(novo.nome, nome, sizeof(novo.nome));
                lista = inserir_ordenado_por_codigo(lista, novo);
                puts("Produto incluído/atualizado.");
            } else {
                puts("Erro no formato ADD");
            }
        } else if (strncmp(linha, "DEL", 3) == 0) {
            char cod[16];
            if (sscanf(linha+3, "%15s", cod) == 1) {
                lista = remover_por_codigo(lista, cod);
                puts("Removido (se existia).");
            }
        } else if (strncmp(linha, "FIND", 4) == 0) {
            char cod[16];
            if (sscanf(linha+4, "%15s", cod) == 1) {
                Produto *p = buscar(lista, cod);
                if (p)
                    printf("Encontrado: %s - %s (qtd=%d preco=%.2f)\n",
                           p->codigo, p->nome, p->qtd, p->preco);
                else puts("Não encontrado.");
            }
        } else if (strncmp(linha, "UPD", 3) == 0) {
            char cod[16]; int delta;
            if (sscanf(linha+3, "%15s %d", cod, &delta) == 2) {
                lista = ajustar_quantidade(lista, cod, delta);
                puts("Quantidade ajustada (se possível).");
            }
        } else {
            puts("Comando inválido.");
        }
    }
    puts("Fim.");
    return 0;
}