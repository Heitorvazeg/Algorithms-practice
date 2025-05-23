#include <bits/stdc++.h>

int nodes = 5;

struct Node {
    int valor;
    std::vector<Node*> vizinhos;

    Node(int d) {
        valor = d;
        vizinhos = {};
    }
};

void bfs(Node* node, std::vector<bool>& visited);

std::vector<Node*> graph(nodes);
std::vector<bool> visited(nodes, false);

int main() {
    for (int i = 0; i < nodes; i++) {
        graph[i] = new Node(i);
    }

    graph[0]->vizinhos = {graph[1], graph[2]};
    graph[1]->vizinhos = {graph[3], graph[4]};

    bfs(graph[0], visited);
}

void bfs(Node* node, std::vector<bool>& visited) {
    std::queue<Node*> fila;

    visited[node->valor] = true;
    fila.push(node);

    while (!fila.empty()) {
        node = fila.front();
        fila.pop();
        std::cout << "Visited: " << node->valor << "\n";

        for (Node* vizinho : node->vizinhos) {
            if (!visited[vizinho->valor]) {
                visited[vizinho->valor] = true;
                fila.push(vizinho);
            }
        }
    }
}