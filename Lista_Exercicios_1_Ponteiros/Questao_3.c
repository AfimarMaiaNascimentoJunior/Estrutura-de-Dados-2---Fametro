/* Exibir endereços e valores com ponteiro */
#include <stdio.h>

int main() {
    int var;
    int *p;
    if (scanf("%d", &var) != 1) return 0;
    p = &var;
    printf("Valor da variavel: %d\n", var);
    printf("Endereco da variavel: %p\n", (void*)&var);
    printf("Valor do ponteiro (endereco): %p\n", (void*)p);
    printf("Valor apontado pelo ponteiro: %d\n", *p);
    return 0;
}
