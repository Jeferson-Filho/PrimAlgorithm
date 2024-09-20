#include "grafos/grafos.h"
#include "../kruskal/kruskal.h"
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

// Implementação do modelo de Erdos Renyi >> Gerar grafos aleatórios
void gerarGrafoErdosRenyi(int grafo[MAX_VERTICES][MAX_VERTICES], Aresta *arestas, int num_vertices, float p, int *num_arestas) {
    *num_arestas = 0;
    
    // Inicializa o grafo com zeros
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            grafo[i][j] = 0;
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            float probabilidade = (float) rand() / RAND_MAX;
            if (probabilidade < p) {
                int peso = rand() % 100 + 1; // Peso entre 1 e 100
                grafo[i][j] = peso;
                grafo[j][i] = peso;
                arestas[*num_arestas].u = i;
                arestas[*num_arestas].v = j;
                arestas[*num_arestas].peso = peso;
                (*num_arestas)++;
            }
        }
    }
}

// Cronometrar tempo de execução do Algoritmo de Kruskal
// TODO: utilizando funções da biblioteca windows.h para cronometrar (podemos alterar para funcionar em qualquer SO)
double medirTempoExecucaoKruskal(int (*algoritmo)(Aresta *, int, int), Aresta *arestas, int num_arestas, int num_vertices) {
    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio);
    int custo = algoritmo(arestas, num_arestas, num_vertices);
    QueryPerformanceCounter(&fim);
    //retorna o tempo de execução e verifica se a MST foi formada
    return (custo == -1) ? -1 : (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart;
}

// Cronometrar tempo de execução do Algoritmo de Prim
double medirTempoExecucaoPrim(int (*algoritmo)(int[MAX_VERTICES][MAX_VERTICES], int), int grafo[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio);
    int custo = algoritmo(grafo, num_vertices);
    QueryPerformanceCounter(&fim);
    // Retorna o tempo de execução e verifica se a MST foi formada
    return (custo == -1) ? -1 : (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart;
}