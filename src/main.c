/**
 * Grafos - Projeto 1
 * 
 * Comparação entre algoritmo de Kruskal e Prim
 * 
 * Beatriz Cavalheri
 * Caio Bohlhalter
 * Eduarda Moreira
 * Jeferson Dietrich
 * Larissa Ferrari
 * Maysa Marques
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "kruskal/kruskal.h"
#include "prim/prim.h"
#include "grafos/grafos.h"
#include "utils/utils.h"

// Função para comparar os algoritmos, realizando testes com diferentes tamanhos de grafos e probabilidade de arestas.
// Para cada teste, é gerado um grafo, medido o tempo e o custo dos algoritmos de Kruskal e Prim, após isso imprime e salva os resultados médios.
void compararAlgoritmos(int num_vertices[], float probabilidade[], int num_testes) {
    Aresta arestas[MAX_VERTICES * MAX_VERTICES];
    int grafo[MAX_VERTICES][MAX_VERTICES];
    
    // Arrays para armazenar custos acumulados
    float custos_kruskal[10] = {0};
    float custos_prim[10] = {0};

    // Abrir o arquivo para escrever os resultados
    FILE *arquivo = fopen("resultados.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os resultados.\n");
        return;
    }

    // Escrever cabeçalho no arquivo CSV
    fprintf(arquivo, "n,p,tempo_kruskal,custo_kruskal,desvio_kruskal,tempo_prim,custo_prim,desvio_prim\n");

    for (int i = 0; i < num_testes; i++) {
        int n = num_vertices[i];
        float p = probabilidade[i];
        
        printf("--- Testando com n = %d e p = %.2f\n", n, p);

        double tempo_kruskal = 0, tempo_prim = 0;
        bool mensagemImprimida = false; //variável de controle

        for (int j = 0; j < 10; j++) {
            int num_arestas;
            gerarGrafoErdosRenyi(grafo, arestas, n, p, &num_arestas);

            // Verifica se o número de arestas é suficiente para formar uma MST
            if (num_arestas < n - 1) {
                if (!mensagemImprimida) { //imprime a mensagem apenas uma vez
                    printf("- Número insuficiente de arestas para formar uma MST. É necessário ter pelo menos %d arestas.\n", n - 1);
                    mensagemImprimida = true; // Atualiza a variável para evitar novas impressões
                }
                continue;
            }

            // Cálculo de tempo e custo dos algoritmos
            double tempo_k = medirTempoExecucaoKruskal(kruskal, arestas, num_arestas, n);
            if (tempo_k != -1) {
                tempo_kruskal += tempo_k;
                custos_kruskal[j] = kruskal(arestas, num_arestas, n);
            }

            double tempo_p = medirTempoExecucaoPrim(prim, grafo, n);
            if (tempo_p != -1) {
                tempo_prim += tempo_p;
                custos_prim[j] = prim(grafo, n);
            }
        }

        // Cálculo de médio e desvio-padrão
        if (tempo_kruskal > 0) {
            tempo_kruskal /= 10;
            float custo_medio_kruskal = calcularMedia(custos_kruskal, 10);
            double desvio_padrao_kruskal = calcularDesvioPadrao(custos_kruskal, 10);
            printf("- Tempo médio Kruskal: %.6f s\n", tempo_kruskal);
            printf("- Custo médio Kruskal: %.2f\n", custo_medio_kruskal);
            printf("- Desvio padrão Kruskal: %.2f\n", desvio_padrao_kruskal);

            // Escrever resultados de Kruskal no arquivo
            fprintf(arquivo, "%d,%.2f,%.6f,%.2f,%.2f,", n, p, tempo_kruskal, custo_medio_kruskal, desvio_padrao_kruskal);
        }

        if (tempo_prim > 0) {
            tempo_prim /= 10;
            float custo_medio_prim = calcularMedia(custos_prim, 10);
            double desvio_padrao_prim = calcularDesvioPadrao(custos_prim, 10);
            printf("- Tempo médio Prim: %.6f s\n", tempo_prim);
            printf("- Custo médio Prim: %.2f\n", custo_medio_prim);
            printf("- Desvio padrão Prim: %.2f\n", desvio_padrao_prim);

            // Completar a linha com os resultados de Prim
            fprintf(arquivo, "%.6f,%.2f,%.2f\n", tempo_prim, custo_medio_prim, desvio_padrao_prim);
        }

        printf("\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
    printf("Resultados salvos no arquivo 'resultados.csv'.\n");
}

int main() {
    srand(time(0));

    int num_vertices[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float probabilidade[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int num_testes = 10;

    compararAlgoritmos(num_vertices, probabilidade, num_testes);

    return 0;
}
