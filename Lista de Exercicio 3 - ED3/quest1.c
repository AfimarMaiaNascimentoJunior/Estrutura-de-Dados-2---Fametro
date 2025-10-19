#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50

typedef struct {
    int topo;
    int dados[MAX];
} Pilha;

// Funções básicas da Pilha
void criaPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
    } else {
        p->topo++;
        p->dados[p->topo] = valor;
    }
}

int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    } else {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    }
}

int tamanhoPilha(Pilha *p) {
    return p->topo + 1;
}

void saoIguais(Pilha *p1, Pilha *p2) {
    if (tamanhoPilha(p1) != tamanhoPilha(p2)) {
        printf("As pilhas nao sao iguais.\n");
        if (tamanhoPilha(p1) > tamanhoPilha(p2)) { // 
            printf("A pilha P1 e maior (possui %d elementos).\n", tamanhoPilha(p1));
        } else {
            printf("A pilha P2 e maior (possui %d elementos).\n", tamanhoPilha(p2)); // 
        }
        return;
    }

    Pilha aux1, aux2;
    criaPilha(&aux1);
    criaPilha(&aux2);
    int sao_iguais = 1;

    // Esvazia P1 e P2, comparando e guardando em aux
    while (!pilhaVazia(p1)) {
        int v1 = pop(p1);
        int v2 = pop(p2);
        if (v1 != v2) {
            sao_iguais = 0;
        }
        push(&aux1, v1);
        push(&aux2, v2);
    }

    // Restaura P1 e P2
    while (!pilhaVazia(&aux1)) {
        push(p1, pop(&aux1));
        push(p2, pop(&aux2));
    }

    if (sao_iguais) {
        printf("As pilhas P1 e P2 sao iguais.\n"); // 
    } else {
        printf("As pilhas P1 e P2 nao sao iguais (mesmo tamanho, valores diferentes).\n");
    }
}

// 
void estatisticasPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("A pilha esta vazia. Nao ha estatisticas.\n");
        return;
    }

    Pilha aux;
    criaPilha(&aux);

    int maior = INT_MIN;
    int menor = INT_MAX;
    double soma = 0;
    int contador = 0;

    // Esvazia p, calcula e guarda em aux
    while (!pilhaVazia(p)) {
        int valor = pop(p);
        if (valor > maior) maior = valor;
        if (valor < menor) menor = valor;
        soma += valor;
        contador++;
        push(&aux, valor);
    }

    // Restaura p
    while (!pilhaVazia(&aux)) {
        push(p, pop(&aux));
    }

    printf("Estatisticas da Pilha:\n");
    printf("Maior elemento: %d\n", maior); // 
    printf("Menor elemento: %d\n", menor); // 
    printf("Media aritmetica: %.2f\n", soma / contador); // 
}

// 
void transfereP1paraP2(Pilha *p1, Pilha *p2) {
    Pilha aux;
    criaPilha(&aux);
    criaPilha(p2); // Limpa P2

    // Esvazia P1 e guarda em Aux (invertendo a ordem)
    while (!pilhaVazia(p1)) {
        push(&aux, pop(p1));
    }

    // Esvazia Aux, restaurando P1 e copiando para P2
    while (!pilhaVazia(&aux)) {
        int valor = pop(&aux);
        push(p1, valor); // Restaura P1
        push(p2, valor); // Copia para P2
    }
    printf("Elementos de P1 transferidos (copiados) para P2.\n");
}

// 
int contaImpares(Pilha *p) {
    Pilha aux;
    criaPilha(&aux);
    int impares = 0;

    while (!pilhaVazia(p)) {
        int valor = pop(p);
        if (valor % 2 != 0) {
            impares++;
        }
        push(&aux, valor);
    }
    // Restaura p
    while (!pilhaVazia(&aux)) {
        push(p, pop(&aux));
    }
    return impares;
}

// 
int contaPares(Pilha *p) {
    Pilha aux;
    criaPilha(&aux);
    int pares = 0;

    while (!pilhaVazia(p)) {
        int valor = pop(p);
        if (valor % 2 == 0) {
            pares++;
        }
        push(&aux, valor);
    }
    // Restaura p
    while (!pilhaVazia(&aux)) {
        push(p, pop(&aux));
    }
    return pares;
}

void preencherPilha(Pilha *p, char nomePilha) {
    int n, valor;
    printf("Quantos elementos deseja inserir na Pilha %c? ", nomePilha);
    scanf("%d", &n);
    for (int i = 0; i < n && i < MAX; i++) {
        printf("Digite o valor %d para P%c: ", i + 1, nomePilha);
        scanf("%d", &valor);
        push(p, valor);
    }
}

int main() {
    Pilha P1, P2;
    criaPilha(&P1);
    criaPilha(&P2);

    printf("--- Preenchendo Pilha P1 ---\n");
    preencherPilha(&P1, '1');
    printf("\n--- Preenchendo Pilha P2 ---\n");
    preencherPilha(&P2, '2');

    printf("\n--- 1. Teste de Igualdade ---\n");
    saoIguais(&P1, &P2);

    printf("\n--- 2. Estatisticas de P1 ---\n"); 
    estatisticasPilha(&P1);
    
    printf("\n--- 3. Contagem Pares/Impares P1 ---\n");
    printf("P1 tem %d elementos pares.\n", contaPares(&P1)); 
    printf("P1 tem %d elementos impares.\n", contaImpares(&P1)); 

    printf("\n--- 4. Transferir P1 para P2 ---\n");
    transfereP1paraP2(&P1, &P2);
    
    printf("\n--- 5. Estatisticas de P2 (apos copia) ---\n");
    estatisticasPilha(&P2);

    return 0;
}

