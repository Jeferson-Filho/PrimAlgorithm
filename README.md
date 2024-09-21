[![Contributors][contributors-shield]][contributors-url]

<div align="center">
  <h1 align="center">Graph Theory Project: Prim's Algorithm vs Kruskal's Algorithm</h1>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributors">Contributors</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project
This project focuses on implementing and comparing two well-known algorithms for finding Minimum Spanning Trees (MST) in graphs: Prim's Algorithm and Kruskal's Algorithm. The graphs used in the comparison are generated using the Erdős-Rényi random graph model.

### Statement
* Implement Prim's algorithm.
* Compare it with Kruskal's algorithm using the Erdős-Rényi model.
   * Use different values for **p** and the graph's order **n** for comparison.
   * Use at least 10 different values for **p** and 10 for **n**. For each pair of values, examine at least 10 random graphs.
   * Compare the execution time of the algorithms.
   * Discuss how the minimum cost for the trees depends on **p** and **n**. In this analysis, you may divide the values by **n** to normalize them.
* Calculate the mean and standard deviation of the quantities of interest.
* Present your results in the form of graphs or tables.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

[![Next][Cpp]][Cpp-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

To compile the project, use ´gcc -mconsole .\main.c .\kruskal\kruskal.c .\prim\prim.c .\grafos\grafos.c .\utils\utils.c -o grafos´
After this, execute '.\grafos'

### Prerequisites

### Installation

Instalação de ferramentas necessárias para rodar o projeto (verificar se será necessário)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

### Algorithms
- [X] Generate Erdős-Rényi Graphs
    - [X] Write a function to generate random graphs using the Erdős-Rényi model
    - [X] Test graph generation with different values of n and p
- [X] Implement Prim's Algorithm
    - [X] Define graph representation (adjacency list or matrix)
    - [X] Write Prim's Algorithm function
    - [X] Test Prim's Algorithm on small graphs
- [X] Implement Kruskal's Algorithm
    - [X] Define union-find (disjoint-set) data structure
    - [X] Write Kruskal's Algorithm function
    - [X] Test Kruskal's Algorithm on small graphs

### Analysis
- [X] Performance Comparison
    - [X] Implement function to measure execution time (Prim and Kruskal)
    - [X] Test performance comparison on small graphs
    - [X] Run experiments with different values of p (at least 10 values)
    - [X] Run experiments with different values of n (at least 10 values)
    - [ ] For each pair of p and n, analyze at least 10 random graphs
- [X] Statistical Analysis
    - [X] Calculate mean and standard deviation of MST costs and execution times
    - [ ] Normalize results by dividing by n
- [ ] Results Presentation
    - [ ] Plot execution time vs. p and n (use Gnuplot, Matplotlib C++ or export data to a CSV and use Python/Excel for plotting)
    - [ ] Plot MST cost vs. p and n
    - [ ] Create tables for statistical data (mean, standard deviation)
- [ ] Discussion and Conclusion
    - [ ] Discuss performance differences between Prim and Kruskal
    - [ ] Analyze how the values of p and n affect MST cost
    - [ ] Write a conclusion summarizing the findings

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributors

<a href="https://github.com/Jeferson-Filho/PrimAlgorithm/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Jeferson-Filho/PrimAlgorithm" alt="contrib.rocks image" />
</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Quem quiser colocar um meio de contato, escreve aqui
Jeferson Filho - [LinkedIn](https://www.linkedin.com/in/jdietrichfho/)
Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Colocar aqui as fontes ou páginas/coisas que julguem interessante para compor o projeto

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Jeferson-Filho/PrimAlgorithm.svg?style=for-the-badge
[contributors-url]: https://github.com/Jeferson-Filho/PrimAlgorithm/graphs/contributors
[Cpp]: https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white
[Cpp-url]: https://devdocs.io/cpp/
