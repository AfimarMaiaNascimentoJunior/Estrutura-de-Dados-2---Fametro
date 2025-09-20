/*Encontrar maior e menor usando ponteiros */
#include <stdio.h>

void encontrarMaiorMenor(int *array, int tamanho, int *maior, int *menor) {
    if (tamanho <= 0) return;
    *maior = array[0];
    *menor = array[0];
    for (int i = 1; i < tamanho; ++i) {
        if (array[i] > *maior) *maior = array[i];
        if (array[i] < *menor) *menor = array[i];
    }
}

int main() {
    int n;
    printf("Digite o numero da lista:\n");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    printf("Digite a lista:\n");
    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    int maior, menor;
    encontrarMaiorMenor(arr, n, &maior, &menor);
    printf("Maior: %d\nMenor: %d\n", maior, menor);
    return 0;
}