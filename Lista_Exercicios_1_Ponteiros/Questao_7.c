/*Inverter string in-place usando ponteiros */
#include <stdio.h>
#include <string.h>

void inverterString(char *str) {
    if (str == NULL) return;
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int main() {
    char s[2048];
    if (fgets(s, sizeof(s), stdin) == NULL) return 0;
    /* remover newline */
    size_t i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\n') { s[i] = '\0'; break; }
        i++;
    }
    inverterString(s);
    printf("%s\n", s);
    return 0;
}
