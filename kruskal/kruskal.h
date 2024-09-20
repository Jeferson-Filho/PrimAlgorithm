#ifndef KRUSKAL_H
#define KRUSKAL_H

// Limitador de quantidade de vértices do grafo
#define MAX_VERTICES 100

// Estrutura padrão de uma aresta (ponderada)
typedef struct {
    int u, v, peso;
} Aresta;

int kruskal(Aresta *arestas, int num_arestas, int num_vertices);

int encontrar(int x);

int compara(const void *a, const void *b);

void unir(int x, int y);

#endif
