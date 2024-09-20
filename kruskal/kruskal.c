#include "kruskal/kruskal.h"
#include <stdlib.h>

// Utilizado para implementar a estrutura de conjuntos disjuntos
int pai[MAX_VERTICES];

// Retorna o representante do conjunto ao qual o elemento x pertence
int encontrar(int x) {
    // Recursão para otimização
    if (pai[x] == x) return x;
    return encontrar(pai[x]);
}

// Conecta dois conjuntos unindo x e y
void unir(int x, int y) {
    pai[encontrar(x)] = encontrar(y);
}

// Compara duas arestaspara ordená-las de acordo com os pesos no qsort
int compara(const void *a, const void *b) {
    Aresta *aresta1 = (Aresta *)a;
    Aresta *aresta2 = (Aresta *)b;
    return aresta1->peso - aresta2->peso;
}

// Implementação do Algoritmo de Kruskal
int kruskal(Aresta *arestas, int num_arestas, int num_vertices) {
    qsort(arestas, num_arestas, sizeof(Aresta), compara);
    for (int i = 0; i < num_vertices; i++) pai[i] = i;
    
    int peso_total = 0, arestas_incluidas = 0;
    
    for (int i = 0; i < num_arestas && arestas_incluidas < num_vertices - 1; i++) {
        int u = arestas[i].u;
        int v = arestas[i].v;

        if (encontrar(u) != encontrar(v)) {
            peso_total += arestas[i].peso;
            unir(u, v);
            arestas_incluidas++;
        }
    }

    if (arestas_incluidas != num_vertices - 1) {
        return -1; 
    }

    return peso_total;
}
