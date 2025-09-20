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
    scanf("%f %f", &a, &b);
        
    float s, su, m, d;
    
    calculadora(a, b, &s, &su, &m, &d);
    
    printf("Soma: %.6g\nSubtracao: %.6g\nMultiplicacao: %.6g\nDivisao: %.6g\n", s, su, m,d);
    return 0;
}

