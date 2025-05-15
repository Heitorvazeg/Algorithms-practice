/*É usado para percorrer uma arvore ou grafo; é feito 1 level por vez.
Utiliza de lógica de fila ao invez de pilha. Pra cada level os nós do level passado saem da
fila.*/

#include <iostream>
#include <vector>
#include <queue>

void bfs(int src, std::vector<std::vector<int>>& matriz);

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

    bfs(0, matriz);
}

void bfs(int src, std::vector<std::vector<int>>& matriz) {
    std::queue<int> fila;
    std::vector<bool> visited(matriz.size(), false);

    fila.push(src);
    visited[src] = true;

    while (fila.size() != 0){
        src = fila.front();
        std::cout << src << " visited\n";
        fila.pop();

        for (int i = 0; i < matriz[src].size(); i++) {
            if (matriz[src][i] == 1 && !visited[i]) {
                fila.push(i);
                visited[i] = true;
            }
        }
    }
}