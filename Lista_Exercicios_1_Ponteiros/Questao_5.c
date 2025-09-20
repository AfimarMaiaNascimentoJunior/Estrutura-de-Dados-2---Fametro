/*Copiar string sem strcpy usando ponteiros */
#include <stdio.h>

void copiarString(char *origem, char *destino) {
    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }
    *destino = '\0';
}

int main() {
    char origem[1000];
    char destino[100];
    if (fgets(origem, sizeof(origem), stdin) == NULL) return 0;
    size_t i = 0;
    while (origem[i] != '\0') {
        if (origem[i] == '\n') { origem[i] = '\0'; break; }
        i++;
    }
    copiarString(origem, destino);
    printf("%s\n", destino);
    return 0;
}
