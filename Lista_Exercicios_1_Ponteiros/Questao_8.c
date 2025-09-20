/* Calculadora básica: soma, subtração, multiplicação e divisão usando ponteiros */
#include <stdio.h>

void calculadora(float a, float b, float *soma, float *sub, float *mult, float *divisao) {
    if (soma) *soma = a + b;
    if (sub) *sub = a - b;
    if (mult) *mult = a * b;
    if (divisao) {
        if (b != 0.0f) *divisao = a / b;
        else *divisao = 0.0f;
    }
}

int main() {
    float a, b;
    if (scanf("%f %f", &a, &b) != 2) return 0;
    float s, su, m, d;
    calculadora(a, b, &s, &su, &m, &d);
    printf("Soma: %.6g\nSubtracao: %.6g\nMultiplicacao: %.6g\n", s, su, m);
    if (b == 0.0f) {
        printf("Divisao: erro (divisao por zero)\n");
    } else {
        printf("Divisao: %.6g\n", d);
    }
    return 0;
}
