/*Dobrar o valor usando ponteiro */
#include <stdio.h>

void dobrar(int *n) {
    *n = (*n) * 2;
}

int main() {
    int x;
    if (scanf("%d", &x) != 1) return 0;
    dobrar(&x);
    printf("%d\n", x);
    return 0;
}
