// ================================================
// MONTAGEM DA TORRE DE FUGA -  DESAFIO FREE FIRE
// ================================================
//
// OBJETIVO:
// Implementar algoritmos de ordenação e busca para gerenciar
// componentes essenciais na montagem de uma torre de fuga
// em um cenário de sobrevivência no jogo Free Fire.
//
// DESCRIÇÃO:
// O programa permite cadastrar componentes com atributos
// como nome, tipo e prioridade. Em seguida, oferece opções
// para ordenar esses componentes usando diferentes algoritmos  
// de ordenação (Bubble Sort, Insertion Sort, Selection Sort)   
// e realizar buscas binárias para localizar componentes-chave. 
// O desempenho de cada algoritmo é medido em termos de tempo
// de execução e número de comparações realizadas.  
// O usuário interage com o programa por meio de um menu
// intuitivo, facilitando a gestão eficiente dos recursos
// necessários para a construção da torre de fuga.
//
// =================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMP 20

// --- ESTRUTURA PRINCIPAL ---
// Representa um componente da torre de fuga
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// --- VARIÁVEIS GLOBAIS ---
// Contador de comparações para análise de desempenho
int comparacoes = 0;

// --- PROTÓTIPOS ---
// Funções principais
void cadastrarComponentes(Componente comp[], int *total);
void mostrarComponentes(Componente comp[], int total);
void bubbleSortNome(Componente comp[], int total);
void insertionSortTipo(Componente comp[], int total);
void selectionSortPrioridade(Componente comp[], int total);
int buscaBinariaPorNome(Componente comp[], int total, char chave[]);
void menuPrincipal();
void medirTempo(void (*algoritmo)(Componente[], int), Componente comp[], int total);

// --- FUNÇÃO PRINCIPAL ---
// Inicia o programa e exibe o menu principal
int main() {
    menuPrincipal();
    return 0;
}

// --- MENU PRINCIPAL ---
// Exibe as opções e gerencia a interação do usuário
void menuPrincipal() {
    Componente torre[MAX_COMP];
    int total = 0;
    int opcao;
    char chave[30];

    do {
        printf("\n==============================\n");
        printf("MONTAGEM DA TORRE DE FUGA\n");
        printf("==============================\n");
        printf("1-  Cadastrar componentes\n");
        printf("2-  Mostrar componentes\n");
        printf("3-  Ordenar por nome (Bubble Sort)\n");
        printf("4-  Ordenar por tipo (Insertion Sort)\n");
        printf("5-  Ordenar por prioridade (Selection Sort)\n");
        printf("6-  Buscar componente-chave (Binaria)\n");
        printf("0-  Encerrar missao\n");
        printf("-------------------------------\n");
        printf("Escolha sua acao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarComponentes(torre, &total);
                break;
            case 2:
                mostrarComponentes(torre, total);
                break;
            case 3:
                medirTempo(bubbleSortNome, torre, total);
                break;
            case 4:
                medirTempo(insertionSortTipo, torre, total);
                break;
            case 5:
                medirTempo(selectionSortPrioridade, torre, total);
                break;
            case 6:
                if (total == 0) {
                    printf("\nNenhum componente cadastrado!\n");
                    break;
                }
                printf("\nDigite o nome do componente-chave: ");
                fgets(chave, 30, stdin);
                chave[strcspn(chave, "\n")] = '\0';
                printf("\nIniciando busca binaria otimizada...\n");
                clock_t inicio = clock();
                int pos = buscaBinariaPorNome(torre, total, chave);
                clock_t fim = clock();
                double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                if (pos != -1)
                    printf("Componente encontrado: %s | Tipo: %s | Prioridade: %d\n",
                           torre[pos].nome, torre[pos].tipo, torre[pos].prioridade);
                else
                    printf("Componente nao encontrado!\n");
                printf("Comparaçoes: %d | Tempo: %.6f s\n", comparacoes, tempo);
                break;
            case 0:
                printf("\nFim da missao. Torre de fuga concluida!\n");
                break;
            default:
                printf("\nOpçao invalida!\n");
        }

    } while (opcao != 0);
}

// ==================================
// FUNÇÕES DE CADASTRO E EXIBIÇÃO
// ==================================
void cadastrarComponentes(Componente comp[], int *total) {
    if (*total >= MAX_COMP) {
        printf("\nLimite maximo atingido!\n");
        return;
    }

    int qtd;
    printf("\nQuantos componentes deseja adicionar (max %d)? ", MAX_COMP - *total);
    scanf("%d", &qtd);
    getchar();

    for (int i = 0; i < qtd && *total < MAX_COMP; i++) {
        printf("\n=== CADASTRO DO COMPONENTE %d ===\n", *total + 1);
        printf("Nome: ");
        fgets(comp[*total].nome, 30, stdin);
        comp[*total].nome[strcspn(comp[*total].nome, "\n")] = '\0';
        printf("Tipo: ");
        fgets(comp[*total].tipo, 20, stdin);
        comp[*total].tipo[strcspn(comp[*total].tipo, "\n")] = '\0';
        printf("Prioridade (1-10): ");
        scanf("%d", &comp[*total].prioridade);
        getchar();
        (*total)++;
    }

    printf("\nComponentes adicionados com sucesso!\n");
}

void mostrarComponentes(Componente comp[], int total) {
    if (total == 0) {
        printf("\nNenhum componente cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE COMPONENTES ===\n");
    for (int i = 0; i < total; i++) {
        printf("%2d️⃣  %-20s | %-15s | Prioridade: %d\n",
               i + 1, comp[i].nome, comp[i].tipo, comp[i].prioridade);
    }
}

// =========================
// ALGORITMOS DE ORDENAÇÃO
// =========================

// --- Bubble Sort (por nome) ---
void bubbleSortNome(Componente comp[], int total) {
    comparacoes = 0;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            comparacoes++;
            if (strcmp(comp[j].nome, comp[j + 1].nome) > 0) {
                Componente temp = comp[j];
                comp[j] = comp[j + 1];
                comp[j + 1] = temp;
            }
        }
    }
    printf("\nOrdenado por nome (Bubble Sort)\n");
    mostrarComponentes(comp, total);
    printf("Comparaçoes: %d\n", comparacoes);
}

// --- Insertion Sort (por tipo) ---
void insertionSortTipo(Componente comp[], int total) {
    comparacoes = 0;
    for (int i = 1; i < total; i++) {
        Componente chave = comp[i];
        int j = i - 1;
        while (j >= 0 && strcmp(comp[j].tipo, chave.tipo) > 0) {
            comp[j + 1] = comp[j];
            j--;
            comparacoes++;
        }
        comp[j + 1] = chave;
    }
    printf("\nOrdenado por tipo (Insertion Sort)\n");
    mostrarComponentes(comp, total);
    printf("Comparaçoes: %d\n", comparacoes);
}

// --- Selection Sort (por prioridade) ---
void selectionSortPrioridade(Componente comp[], int total) {
    comparacoes = 0;
    for (int i = 0; i < total - 1; i++) {
        int min = i;
        for (int j = i + 1; j < total; j++) {
            comparacoes++;
            if (comp[j].prioridade < comp[min].prioridade)
                min = j;
        }
        if (min != i) {
            Componente temp = comp[i];
            comp[i] = comp[min];
            comp[min] = temp;
        }
    }
    printf("\nOrdenado por prioridade (Selection Sort)\n");
    mostrarComponentes(comp, total);
    printf("Comparaçoes: %d\n", comparacoes);
}

// =================================================
// BUSCA BINÁRIA (apenas após ordenação por nome)
// =================================================
int buscaBinariaPorNome(Componente comp[], int total, char chave[]) {
    int inicio = 0, fim = total - 1;
    comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        int cmp = strcmp(chave, comp[meio].nome);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}

// =================================
// FUNÇÃO DE MEDIÇÃO DE DESEMPENHO
// =================================
void medirTempo(void (*algoritmo)(Componente[], int), Componente comp[], int total) {
    if (total == 0) {
        printf("\nNenhum componente cadastrado!\n");
        return;
    }

    clock_t inicio = clock();
    algoritmo(comp, total);
    clock_t fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo);
}
