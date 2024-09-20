#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kruskal.h"
#include "prim.h"
#include "grafo.h"
#include "utils.h"

int main() {
    srand(time(0));

    int num_vertices[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float probabilidade[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int num_testes = 10;

    compararAlgoritmos(num_vertices, probabilidade, num_testes);

    return 0;
}
