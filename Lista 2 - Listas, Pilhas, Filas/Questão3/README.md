
# Questão 3 - Pilha de Processos

## Compilação
```
gcc main.c pilha.c -o processos
./processos
```

## Exemplo
```
CALL main 100
CALL f1 80
PEEK
TRACE
RET
TRACE
EXIT
```
## Complexidade
````
Inicializar: O(1)
Push: O(1)
Pop: O(1)
Topo/peek: O(1)
Trace : O(n)
Limpar: O(n)
````
