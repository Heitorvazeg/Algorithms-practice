/*Um algoritmo de busca para atravessar um grafo ou uma arvore.
Pegue uma rota; continue nela até achar um deadEnd ou um nó ja visitado; 
backtrack pro nó anterior que possui vizinhos não visitados.
Utiliza de logica de pilha pra poder anotar os nós já visitados.*/

#include <iostream>
#include <vector>

void DFS(int src, const std::vector<std::vector<int>>& matriz);
void DFShelper(int src, std::vector<bool>& visited, const std::vector<std::vector<int>>& matriz);

int main() {
    int nodes = 5;
    std::vector<std::vector<int>> matriz(nodes, std::vector<int>(nodes, 0));

    matriz[0][1] = 1;
    matriz[1][0] = 1;

    matriz[0][2] = 1;
    matriz[2][0] = 1;

    matriz[1][3] = 1;
    matriz[3][1] = 1;

    matriz[2][3] = 1;
    matriz[3][2] = 1;

    DFS(2, matriz);
}

void DFS(int src, const std::vector<std::vector<int>>& matriz) {
    int size = matriz.size();
    std::vector<bool> visited(size, false);

    DFShelper(src, visited, matriz);
}

void DFShelper(int src, std::vector<bool>& visited, const std::vector<std::vector<int>>& matriz) {
    if (visited[src]) {
        return;

    } else {
        visited[src] = true;
        std::cout << src << " visited\n";
    }

    for (int i = 0; i < matriz.size(); i++) {
        if (matriz[src][i] == 1) {
            DFShelper(i, visited, matriz);
        }
    }
    return;
}