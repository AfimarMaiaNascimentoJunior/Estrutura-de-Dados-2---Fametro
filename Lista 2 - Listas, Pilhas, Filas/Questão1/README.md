
# Questão 1 (versão reescrita) - Lista de Estoque

## Como compilar
```
gcc main.c produto.c -o estoque
./estoque
```

## Exemplo
```
ADD P10 "Caderno" 20 15.5
ADD P05 "Caneta" 100 2.0
LIST
REL
UPD P05 -20
LIST
EXIT
```

## Complexidade
- Inserção ordenada: O(n)
- Exclusão: O(n)
- Alterar quantidade: O(n)
- Localizar: O(n)
- Exibir: O(n)
- Destruir: O(n)
