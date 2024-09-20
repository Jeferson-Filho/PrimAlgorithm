#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <math.h>


//função para gerar grafos aleatórios usando o modelo Erdős-Rényi
void gerarGrafoErdosRenyi(int grafo[MAX_VERTICES][MAX_VERTICES], Aresta *arestas, int num_vertices, float p, int *num_arestas) {
    *num_arestas = 0;
    //inicializa o grafo com zeros
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            grafo[i][j] = 0;
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            float probabilidade = (float) rand() / RAND_MAX;
            if (probabilidade < p) {
                int peso = rand() % 100 + 1; //peso entre 1 e 100
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

//função que mede o tempo que o algoritmo de Kruskal leva para ser executado
//utilizando funções da biblioteca windows.h para cronometrar (podemos alterar para funcionar em qualquer SO)
double medirTempoExecucaoKruskal(int (*algoritmo)(Aresta *, int, int), Aresta *arestas, int num_arestas, int num_vertices) {
    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio);
    int custo = algoritmo(arestas, num_arestas, num_vertices);
    QueryPerformanceCounter(&fim);
    //retorna o tempo de execução e verifica se a MST foi formada
    return (custo == -1) ? -1 : (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart;
}

//função para medir o tempo de execução do Prim
double medirTempoExecucaoPrim(int (*algoritmo)(int[MAX_VERTICES][MAX_VERTICES], int), int grafo[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    LARGE_INTEGER inicio, fim, frequencia;
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&inicio);
    int custo = algoritmo(grafo, num_vertices);
    QueryPerformanceCounter(&fim);
    //retorna o tempo de execução e verifica se a MST foi formada
    return (custo == -1) ? -1 : (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart;
}

//função para calcular a média
double calcularMedia(float *custos, int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += custos[i];
    }
    return soma / n;
}

//função para calcular o desvio padrão
double calcularDesvioPadrao(float *custos, int n) {
    double media = calcularMedia(custos, n);
    double soma_variancia = 0;
    for (int i = 0; i < n; i++) {
        soma_variancia += (custos[i] - media) * (custos[i] - media);
    }
    return sqrt(soma_variancia / n);
}

//função principal para comparação
//realiza testes com diferentes tamanhos de grafo e probabilidades de arestas
//para cada teste, ela gera um grafo, mede o tempo e o custo dos algoritmos de Kruskal e Prim, e imprime os resultados médios.
void compararAlgoritmos(int num_vertices[], float probabilidade[], int num_testes) {
    Aresta arestas[MAX_VERTICES * MAX_VERTICES];
    int grafo[MAX_VERTICES][MAX_VERTICES];
    
    //arrays para armazenar custos acumulados
    float custos_kruskal[10] = {0};
    float custos_prim[10] = {0};

    for (int i = 0; i < num_testes; i++) {
        int n = num_vertices[i];
        float p = probabilidade[i];
        
        printf("--- Testando com n = %d e p = %.2f\n", n, p);

        double tempo_kruskal = 0, tempo_prim = 0;
        bool mensagemImprimida = false; //variável de controle

        for (int j = 0; j < 10; j++) {
            int num_arestas;
            gerarGrafoErdosRenyi(grafo, arestas, n, p, &num_arestas);

            //verifica se o número de arestas é suficiente para formar uma MST
            if (num_arestas < n - 1) {
                if (!mensagemImprimida) { //imprime a mensagem apenas uma vez
                    printf("- Número insuficiente de arestas para formar uma MST. É necessário ter pelo menos %d arestas.\n", n - 1);
                    mensagemImprimida = true; //atualiza a variável para evitar novas impressões
                }
                continue; // Passa para o próximo teste
            }

            //medir tempo e custo de Kruskal
            double tempo_k = medirTempoExecucaoKruskal(kruskal, arestas, num_arestas, n);
            if (tempo_k != -1) {
                tempo_kruskal += tempo_k;
                custos_kruskal[j] = kruskal(arestas, num_arestas, n);
            }

            //medir tempo e custo de Prim
            double tempo_p = medirTempoExecucaoPrim(prim, grafo, n);
            if (tempo_p != -1) {
                tempo_prim += tempo_p;
                custos_prim[j] = prim(grafo, n);
            }
        }

        //calcular médias e desvios padrão
        if (tempo_kruskal > 0) {
            tempo_kruskal /= 10;
            float custo_medio_kruskal = calcularMedia(custos_kruskal, 10);
            double desvio_padrao_kruskal = calcularDesvioPadrao(custos_kruskal, 10);
            printf("- Tempo médio Kruskal: %.6f s\n", tempo_kruskal);
            printf("- Custo médio Kruskal: %.2f\n", custo_medio_kruskal);
            printf("- Desvio padrão Kruskal: %.2f\n", desvio_padrao_kruskal);
        }

        if (tempo_prim > 0) {
            tempo_prim /= 10;
            float custo_medio_prim = calcularMedia(custos_prim, 10);
            double desvio_padrao_prim = calcularDesvioPadrao(custos_prim, 10);
            printf("- Tempo médio Prim: %.6f s\n", tempo_prim);
            printf("- Custo médio Prim: %.2f\n", custo_medio_prim);
            printf("- Desvio padrão Prim: %.2f\n", desvio_padrao_prim);
        }

        printf("\n");
    }
}

//inicializamos o gerador de números aleatórios e chamamos a função de comparação com diferentes parâmetros de teste
int main() {
    srand(time(0));

    int num_vertices[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float probabilidade[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int num_testes = 10;

    compararAlgoritmos(num_vertices, probabilidade, num_testes);

    return 0;
}
