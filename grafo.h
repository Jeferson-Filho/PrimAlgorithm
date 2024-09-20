#ifndef GRAFO_H
#define GRAFO_H

#include "kruskal.h"

#define MAX_VERTICES 100

void gerarGrafoErdosRenyi(int grafo[MAX_VERTICES][MAX_VERTICES], Aresta *arestas, int num_vertices, float p, int *num_arestas);

double medirTempoExecucaoKruskal(int (*algoritmo)(Aresta *, int, int), Aresta *arestas, int num_arestas, int num_vertices);

double medirTempoExecucaoPrim(int (*algoritmo)(int[MAX_VERTICES][MAX_VERTICES], int), int grafo[MAX_VERTICES][MAX_VERTICES], int num_vertices);

#endif