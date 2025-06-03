/* Usado para encontrar o menor caminho entre grafos com peso.
Percorre os nós e atualiza uma tabela com os menores caminhos. Coloca os Nós
anteriores na tabela tbm. Sempre que mudar o grafo precisa somar o peso que o levou
até lá. O proximo sempre será o com menor distância. Min-Heap para sempre pegar o
menor. As distancias que vc nao sabe vc aplica como infinito*/

#include <bits/stdc++.h>
const int INF = 1e9;

using namespace std;

int main() {
    int n = 3;
    vector<pair<int, int>> grafo[3];

    grafo[0].push_back({1, 5});
    grafo[0].push_back({2, 1});
    grafo[2].push_back({1, 2});

    vector<int> dist(n, INF);
    dist[0] = 0;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > fila;
    fila.push({0, 0});

    while(!fila.empty()) {
        auto [d, u] = fila.top();
        fila.pop();

        if (d > dist[u]) continue;

        for (auto [v, peso] : grafo[u]) {
            if (dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                fila.push({dist[v], v});
            }
        }
    }
}