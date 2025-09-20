#include <stdio.h>

int main() {
    int var;
    int *p;
    scanf("%d", &var)
    p = &var;
    
    printf("Valor: %d\n", var);
    printf("Endereco: %p\n", (void*)&var);
    printf("Endereço ponteiro: %p\n", (void*)p);
    printf("Valor ponteiro: %d\n", *p);
    return 0;
}

