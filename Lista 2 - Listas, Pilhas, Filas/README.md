# Questão 1 — Controle de Estoque (Versão Reescrita)

## Arquivos
- `estoque.h`
- `estoque.c`
- `main.c`
- `README.md`

## Compilação
```bash
gcc -std=c11 -Wall -Wextra main.c estoque.c -o estoque
```

## Execução
```bash
./estoque
```

## Comandos
- `ADD <cod> "<nome>" <qtd> <preco>`
- `UPD <cod> <delta_qtd>`
- `DEL <cod>`
- `FIND <cod>`
- `LIST`
- `REL`
- `EXIT`

## Complexidade
- Inserção ordenada: O(n)
- Remoção: O(n)
- Alteração de quantidade: O(n)
- Busca: O(n)
- Listagem: O(n)
- Liberação: O(n)
- Relatório: O(n)
