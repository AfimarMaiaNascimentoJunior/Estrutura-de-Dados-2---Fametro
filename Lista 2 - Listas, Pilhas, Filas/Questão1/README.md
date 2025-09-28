# Questão 1 — Lista Encadeada de Produtos

## Arquivos
- `produto.h`
- `produto.c`
- `main.c`
- `README.md`

## Compilação
```bash
gcc -std=c11 -Wall -Wextra main.c produto.c -o estoque
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
- Inserir início: O(1)
- Inserir ordenado: O(n)
- Remover: O(n)
- Ajustar quantidade: O(n)
- Buscar: O(n)
- Listar: O(n)
- Limpar: O(n)
- Relatório: O(n)
