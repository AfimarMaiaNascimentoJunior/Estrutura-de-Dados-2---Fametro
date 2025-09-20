/* Troca de valores usando ponteiros */
#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) return 0;
    trocar(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}
