#include <stdio.h>
#include <string.h>

void inverterString(char *palavra) {
    if (palavra == NULL) return;
    char *comeco = palavra;
    char *fim = palavra + strlen(palavra) - 1;
    while (comeco < fim) {
        char aux = *comeco;
        *comeco = *fim;
        *fim = aux;
        comeco++;
        fim--;
    }
}

int main() {
    char s[100];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    
    size_t i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') { s[i] = '\0'; break; }
        i++;
    }
    inverterString(s);
    printf("%s\n", s);
    return 0;
}

