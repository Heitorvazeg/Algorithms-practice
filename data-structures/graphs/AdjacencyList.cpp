/*Adjacency List: Um array de linkedLists; cada nó seria uma linkedlist armazenada e 
que mostra as suas adjacencias.*/

#include <iostream>
#include <vector>

int nodes = 5;

struct Node {
    int valor;
    std::vector<Node*> vizinhos;

    Node(int d) {
        valor = d;
        vizinhos = {};
    }
};

void dfs(Node* node, std::vector<bool>& visited);

std::vector<Node*> graph(nodes);
std::vector<bool> visited(nodes, false);

int main() {
    for (int i = 0; i < nodes; i++) {
        graph[i] = new Node(i);
    }

    graph[0]->vizinhos = {graph[1], graph[2]};
    graph[1]->vizinhos = {graph[3], graph[4]};
}