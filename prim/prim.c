#include "prim/prim.h"
#include <stdbool.h>
#include <stdlib.h>

// Implementação do Algoritmo de Prim
int prim(int grafo[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    int custo = 0;
    int chave[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < num_vertices; i++) {
        chave[i] = INFINITO;
        mstSet[i] = false;
    }

    chave[0] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = -1, min = INFINITO;

        // Escolhe o vértice com menor chave
        for (int v = 0; v < num_vertices; v++) {
            if (!mstSet[v] && chave[v] < min) {
                min = chave[v];
                u = v;
            }
        }

        mstSet[u] = true;
        custo += min;

        // Atualiza a chave dos vértices adjacentes
        for (int v = 0; v < num_vertices; v++) {
            if (grafo[u][v] && !mstSet[v] && grafo[u][v] < chave[v]) {
                chave[v] = grafo[u][v];
            }
        }
    }

    return custo;
}

