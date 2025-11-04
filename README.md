# Sistema de Organização de Componentes

Este projeto foi desenvolvido em linguagem **C** e simula um sistema que organiza os **componentes de uma torre de resgate**. Ele compara diferentes algoritmos de ordenação e aplica uma busca binária para encontrar um item-chave com mais rapidez.

---

## Objetivo:

O programa permite:

* Cadastrar até **20 componentes** (nome, tipo e prioridade);
* Ordenar os dados com **três algoritmos diferentes**;
* Realizar **busca binária otimizada** após a ordenação por nome;
* Exibir **quantas comparações** e **quanto tempo** cada algoritmo levou.

---

## Estrutura usada:

Cada componente é guardado em uma struct:

```c
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;
```

---

## Algoritmos implementados:

| Algoritmo      | Critério   | Descrição                                               |
| -------------- | ---------- | ------------------------------------------------------- |
| Bubble Sort    | Nome       | Compara pares de itens e troca de posição se necessário |
| Insertion Sort | Tipo       | Insere elementos na posição correta, um por vez         |
| Selection Sort | Prioridade | Busca o menor valor e coloca na posição certa           |
| Busca Binária  | Nome       | Procura um item em lista ordenada de forma rápida       |

---

## Resultados mostrados:

Após cada operação, o sistema exibe:

* Os **componentes ordenados**;
* O número de **comparações realizadas**;
* O **tempo total de execução** (em segundos).

Exemplo:

```
Ordenado por nome (Bubble Sort):
1️⃣ chip central        | controle   | Prioridade: 10
2️⃣ painel de energia   | suporte    | Prioridade: 7
3️⃣ turbina superior    | propulsão  | Prioridade: 4
🔹 Comparações: 23
⏱️ Tempo de execução: 0.000245 segundos
```

---

## Como usar:

1. Compile o código:

   ```bash
   gcc main.c -o torre
   ```

2. Execute o programa:

   ```bash
   ./torre
   ```

3. Use o menu interativo para:

   * Adicionar componentes;
   * Escolher o tipo de ordenação;
   * Realizar a busca binária.

---

## Conceitos aplicados:

* Estruturas de dados (struct e vetores)
* Ordenação clássica (Bubble, Insertion, Selection)
* Busca binária
* Contagem de comparações
* Medição de tempo com `clock()`

---

## Autora:

- Desenvolvido por **Giovanna Fernandes**
- Projeto acadêmico desenvolvido para a disciplina de **Estrutura de Dados**,  
no curso de **Sistemas de Informação**.  

- Tem como objetivo aplicar na prática os conceitos de **análise e comparação de algoritmos** em linguagem **C**.  
