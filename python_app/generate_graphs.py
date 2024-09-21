import pandas as pd
import matplotlib.pyplot as plt
import os

# Definir o caminho do arquivo CSV relativo à pasta python_app
csv_path = os.path.join(os.path.dirname(__file__), '../resultados.csv')

# Leitura do arquivo CSV
df = pd.read_csv(csv_path)

# Definir o diretório onde os gráficos serão salvos
output_dir = os.path.join(os.path.dirname(__file__), 'images')

# Criar o diretório de saída se ele não existir
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# ===========================
# Gráficos usando apenas n
# ===========================

# Gráfico de tempo de execução (apenas n)
plt.figure(figsize=(10, 6))
plt.plot(df['n'], df['tempo_kruskal'], label='Kruskal Tempo', marker='o')
plt.plot(df['n'], df['tempo_prim'], label='Prim Tempo', marker='o')
plt.title('Comparação de Tempo de Execução (apenas n)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'tempo_execucao_n.png')) 
plt.close()

# Gráfico de custo médio (apenas n) com ajuste de escala no eixo y
plt.figure(figsize=(10, 6))
plt.plot(df['n'], df['custo_kruskal'], label='Kruskal Custo Médio', marker='o')
plt.plot(df['n'], df['custo_prim'], label='Prim Custo Médio', marker='o')
plt.title('Comparação de Custo Médio da AGM (apenas n)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Custo Médio')
plt.ylim(150, 500) 
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'custo_medio_n.png')) 
plt.close()

# Gráfico de desvio padrão (apenas n) com ajuste de escala no eixo y
plt.figure(figsize=(10, 6))
plt.plot(df['n'], df['desvio_kruskal'], label='Kruskal Desvio Padrão', marker='o')
plt.plot(df['n'], df['desvio_prim'], label='Prim Desvio Padrão', marker='o')
plt.title('Comparação de Desvio Padrão dos Custos (apenas n)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Desvio Padrão')
plt.ylim(0, 250) 
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'desvio_padrao_n.png')) 
plt.close()

# ===========================
# Gráficos usando n + p
# ===========================


# Gráfico de tempo de execução com p como cor
plt.figure(figsize=(10, 6))
plt.scatter(df['n'], df['tempo_kruskal'], label='Kruskal Tempo', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.scatter(df['n'], df['tempo_prim'], label='Prim Tempo', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.colorbar(label='p (Probabilidade)')
plt.title('Comparação de Tempo de Execução (n + p)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'tempo_execucao_n_p.png')) 
plt.close()

# Gráfico de custo médio com p como cor e ajuste de escala no eixo y
plt.figure(figsize=(10, 6))
plt.scatter(df['n'], df['custo_kruskal'], label='Kruskal Custo Médio', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.scatter(df['n'], df['custo_prim'], label='Prim Custo Médio', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.colorbar(label='p (Probabilidade)')
plt.title('Comparação de Custo Médio da AGM (n + p)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Custo Médio')
plt.ylim(150, 500)  
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'custo_medio_n_p.png')) 
plt.close()

# Gráfico de desvio padrão com p como cor e ajuste de escala no eixo y
plt.figure(figsize=(10, 6))
plt.scatter(df['n'], df['desvio_kruskal'], label='Kruskal Desvio Padrão', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.scatter(df['n'], df['desvio_prim'], label='Prim Desvio Padrão', c=df['p'], cmap='coolwarm', s=100, edgecolors='black')
plt.colorbar(label='p (Probabilidade)')
plt.title('Comparação de Desvio Padrão dos Custos (n + p)')
plt.xlabel('n (Número de vértices)')
plt.ylabel('Desvio Padrão')
plt.ylim(0, 250)  
plt.legend()
plt.grid(True)
plt.savefig(os.path.join(output_dir, 'desvio_padrao_n_p.png')) 
plt.close()
