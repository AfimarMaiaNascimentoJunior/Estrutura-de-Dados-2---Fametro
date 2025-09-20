/* Contagem de vogais e consoantes usando ponteiros */
#include <stdio.h>
#include <ctype.h>

int ehVogal(char c) {
    c = tolower((unsigned char)c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

void contarVogaisConsoantes(char *str, int *vogais, int *consoantes) {
    *vogais = 0;
    *consoantes = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char c = str[i];
        if (isalpha((unsigned char)c)) {
            if (ehVogal(c)) (*vogais)++;
            else (*consoantes)++;
        }
    }
}

int main() {
    char s[100];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    /* remover newline */
    size_t i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') { s[i] = '\0'; break; }
        i++;
    }
    int vogais, consoantes;
    contarVogaisConsoantes(s, &vogais, &consoantes);
    printf("Vogais: %d\nConsoantes: %d\n", vogais, consoantes);
    return 0;
}
