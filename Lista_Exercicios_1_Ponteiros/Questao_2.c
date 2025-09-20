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
    int tamanho;
    printf("Digite o tamanho da lista:\n");
    scanf("%d", &tamanho);
    
    printf("Digite:\n");
    int arr[n];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    
    int maior, menor;
    encontrarMaiorMenor(arr, n, &maior, &menor);
    
    printf("Maior: %d\nMenor: %d\n", maior, menor);
    return 0;

}
