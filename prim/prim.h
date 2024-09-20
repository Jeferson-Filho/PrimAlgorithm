#ifndef PRIM_H
#define PRIM_H

// Limitador de quantidade de vértices do grafo
#define MAX_VERTICES 100
// Ausência de arestas (distância infinita)
#define INFINITO 999999 

// Estrutura padrão de uma aresta (ponderada)
int prim(int grafo[MAX_VERTICES][MAX_VERTICES], int num_vertices);

#endif