#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 // Tamanho máximo para pilha e fila
#define MAX_NOME 50

// --- Estrutura de Aluno (para Pilha) ---
typedef struct {
    int numero; // [cite: 41]
    char nome[MAX_NOME];
} Aluno;

// --- Estrutura de Nota (para Fila) ---
typedef struct {
    int numAluno;
    float nota;
} Nota;

// --- Pilha de Alunos --- 
typedef struct {
    int topo;
    Aluno dados[MAX];
} PilhaAlunos;

// --- Fila de Notas --- 
typedef struct {
    int inicio, fim, total;
    Nota dados[MAX];
} FilaNotas;

// --- Variáveis Globais ---
PilhaAlunos pAlunos;
FilaNotas fNotas;
int proximoNumAluno = 1; // [cite: 41]

// --- Funções da Pilha de Alunos ---
void criaPilhaAlunos() {
    pAlunos.topo = -1;
}
int pilhaAlunosVazia() {
    return pAlunos.topo == -1;
}
int pilhaAlunosCheia() {
    return pAlunos.topo == MAX - 1;
}
void pushAluno(Aluno a) {
    if (pilhaAlunosCheia()) {
        printf("Erro: Pilha de alunos cheia!\n");
    } else {
        pAlunos.topo++;
        pAlunos.dados[pAlunos.topo] = a;
    }
}
Aluno popAluno() {
    // Esta função assume que a pilha não está vazia. 
    // A verificação deve ser feita antes de chamar.
    Aluno a = pAlunos.dados[pAlunos.topo];
    pAlunos.topo--;
    return a;
}

// --- Funções da Fila de Notas ---
void criaFilaNotas() {
    fNotas.inicio = 0;
    fNotas.fim = 0;
    fNotas.total = 0;
}
int filaNotasVazia() {
    return fNotas.total == 0;
}
int filaNotasCheia() {
    return fNotas.total == MAX;
}
void enqueueNota(Nota n) {
    if (filaNotasCheia()) {
        printf("Erro: Fila de notas cheia!\n");
    } else {
        fNotas.dados[fNotas.fim] = n;
        fNotas.fim = (fNotas.fim + 1) % MAX;
        fNotas.total++;
    }
}
void dequeueNota() {
    // Esta função assume que a fila não está vazia.
    // A verificação deve ser feita antes de chamar.
    fNotas.inicio = (fNotas.inicio + 1) % MAX;
    fNotas.total--;
}

// --- Funções Auxiliares (Consultas) ---
int existeAluno(int numAluno) {
    for (int i = 0; i <= pAlunos.topo; i++) {
        if (pAlunos.dados[i].numero == numAluno) {
            return 1; // Existe
        }
    }
    return 0; // Não existe
}

// Retorna 1 se o aluno (numAluno) possui notas na fila
int alunoTemNotas(int numAluno) {
    if (filaNotasVazia()) return 0;
    
    int idx = fNotas.inicio;
    for (int i = 0; i < fNotas.total; i++) {
        if (fNotas.dados[idx].numAluno == numAluno) {
            return 1; // Encontrou nota
        }
        idx = (idx + 1) % MAX;
    }
    return 0; // Nenhuma nota encontrada
}

// --- Funções do Menu ---

// [cite: 32]
void cadastrarAluno() {
    if (pilhaAlunosCheia()) {
        printf("Mensagem: Nao e possivel cadastrar, pilha de alunos cheia.\n");
        return;
    }
    Aluno novoAluno;
    novoAluno.numero = proximoNumAluno; // [cite: 41]
    
    printf("Digite o nome do Aluno %d: ", novoAluno.numero);
    scanf(" %[^\n]", novoAluno.nome); // Lê nome com espaços
    
    pushAluno(novoAluno); // 
    printf("Aluno %s (Numero %d) cadastrado com sucesso.\n", novoAluno.nome, novoAluno.numero);
    proximoNumAluno++;
}

// [cite: 33]
void cadastrarNota() {
    if (filaNotasCheia()) {
        printf("Mensagem: Nao e possivel cadastrar, fila de notas cheia.\n");
        return;
    }
    if (pilhaAlunosVazia()) {
        printf("Mensagem: Cadastre um aluno antes de lancar notas.\n");
        return;
    }

    Nota novaNota;
    printf("Digite o numero do aluno: ");
    scanf("%d", &novaNota.numAluno);

    // 
    if (!existeAluno(novaNota.numAluno)) {
        printf("Mensagem: Aluno (Numero %d) nao cadastrado!\n", novaNota.numAluno); // 
        return;
    }
    
    do {
        printf("Digite a nota (entre 0 e 10): ");
        scanf("%f", &novaNota.nota);
        if (novaNota.nota < 0 || novaNota.nota > 10) { // 
            printf("Nota invalida. Digite novamente.\n");
        }
    } while (novaNota.nota < 0 || novaNota.nota > 10);
    
    enqueueNota(novaNota); // 
    printf("Nota %.2f cadastrada para o aluno %d.\n", novaNota.nota, novaNota.numAluno);
}

// [cite: 34]
void calcularMedia() {
    if (pilhaAlunosVazia()) {
        printf("Aviso: Nao ha alunos cadastrados.\n"); // 
        return;
    }
    
    int numAluno;
    printf("Digite o numero do aluno para calcular a media: ");
    scanf("%d", &numAluno); // 

    char nomeAluno[MAX_NOME] = "";
    int encontrouAluno = 0;

    // Busca nome na pilha
    for (int i = 0; i <= pAlunos.topo; i++) {
        if (pAlunos.dados[i].numero == numAluno) {
            strcpy(nomeAluno, pAlunos.dados[i].nome);
            encontrouAluno = 1;
            break;
        }
    }

    if (!encontrouAluno) {
        printf("Aviso: Aluno (Numero %d) nao existe.\n", numAluno); // 
        return;
    }

    // Busca notas na fila
    float soma = 0;
    int cont = 0;
    int idx = fNotas.inicio;
    for (int i = 0; i < fNotas.total; i++) {
        if (fNotas.dados[idx].numAluno == numAluno) {
            soma += fNotas.dados[idx].nota;
            cont++;
        }
        idx = (idx + 1) % MAX;
    }

    if (cont == 0) {
        printf("Aviso: Nao ha notas cadastradas para o aluno %s (Numero %d).\n", nomeAluno, numAluno); // 
    } else {
        printf("Aluno: %s (Numero %d)\n", nomeAluno, numAluno); // 
        printf("Media: %.2f\n", soma / cont); // 
    }
}

// [cite: 35]
void listarAlunosSemNotas() {
    if (pilhaAlunosVazia()) {
        printf("Nao ha alunos cadastrados.\n");
        return;
    }
    
    printf("Alunos sem notas cadastradas:\n");
    int encontrou = 0;
    for (int i = 0; i <= pAlunos.topo; i++) {
        Aluno a = pAlunos.dados[i];
        if (!alunoTemNotas(a.numero)) {
            printf("- %s (Numero %d)\n", a.nome, a.numero);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("(Todos os alunos possuem pelo menos uma nota)\n");
    }
}

// [cite: 36]
void excluirAluno() {
    if (pilhaAlunosVazia()) {
        printf("Mensagem: Pilha de alunos vazia. Nao ha o que excluir.\n");
        return;
    }

    // Pega o aluno do topo (sem remover ainda)
    Aluno alunoTopo = pAlunos.dados[pAlunos.topo];
    
    // [cite: 47]
    if (alunoTemNotas(alunoTopo.numero)) {
        printf("Mensagem: O aluno %s (Numero %d) nao pode ser excluido pois possui notas.\n", 
               alunoTopo.nome, alunoTopo.numero);
    } else {
        // [cite: 48]
        popAluno(); // Exclui o aluno do topo
        printf("Aluno %s (Numero %d) excluido com sucesso.\n", alunoTopo.nome, alunoTopo.numero);
    }
}

// [cite: 37]
void excluirNota() {
    if (filaNotasVazia()) {
        printf("Mensagem: Fila de notas vazia. Nao ha o que excluir.\n");
        return;
    }

    // 
    Nota notaExcluida = fNotas.dados[fNotas.inicio];
    dequeueNota(); // Remove o primeiro elemento da fila
    
    printf("Nota %.2f (do Aluno %d) excluida com sucesso (FIFO).\n", 
           notaExcluida.nota, notaExcluida.numAluno);
}


void mostrarMenu() {
    printf("\n--- MENU GESTAO ACADEMICA ---\n"); // 
    printf("1- Cadastrar aluno\n");             // [cite: 32]
    printf("2- Cadastrar nota\n");              // [cite: 33]
    printf("3- Calcular a media de um aluno\n"); // [cite: 34]
    printf("4- Listar os nomes dos alunos sem notas\n"); // [cite: 35]
    printf("5- Excluir aluno\n");               // [cite: 36]
    printf("6- Excluir nota\n");                // [cite: 37]
    printf("7- Sair\n");                      // [cite: 38]
    printf("Escolha uma opcao: ");
}

int main() {
    criaPilhaAlunos();
    criaFilaNotas();
    int opcao;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarAluno(); break;    // [cite: 32]
            case 2: cadastrarNota(); break;     // [cite: 33]
            case 3: calcularMedia(); break;     // [cite: 34]
            case 4: listarAlunosSemNotas(); break; // [cite: 35]
            case 5: excluirAluno(); break;      // [cite: 36]
            case 6: excluirNota(); break;       // [cite: 37]
            case 7: printf("Saindo...\n"); break; // [cite: 38]
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
