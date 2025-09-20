#include <stdio.h>

void dobrar(int *num) {
    *num = (*num) * 2;
}

int main() {
    int num;
    scanf("%d", &num)
    dobrar(&num);
    printf("%d\n", num);
    return 0;
}

