#include <bits/stdc++.h>

using namespace std;

long long bizurados = 0;
long long total = 0;

void dfsQuanti(vector<vector<int>>& gr) {

}

void dfsBase(vector<vector<int>>& graph, vector<long long>& sujeira, vector<bool>& visited, int src, 
                        vector<long long>& minSubtree) {
    visited[src] = true;
    minSubtree[src] = sujeira[src];

    for (auto v : graph[src]) {
        if (!visited[v]) {
            dfsBase(graph, sujeira, visited, v, minSubtree);

            minSubtree[src] = min(minSubtree[v], minSubtree[src]);
        }
    }
}

void dfsTipo2(vector<vector<int>>& graph, vector<bool>& visited, int src, 
                        vector<long long>& minSubtree, vector<long long>& qtdOps,
                        int k, long long subt, vector<long long>& sujeira) {
    visited[src] = true;
    qtdOps[src] = max(0LL, (sujeira[src] - subt) / k);
    sujeira[src] -= qtdOps[src]*k;
    bizurados += qtdOps[src];
    subt += k*qtdOps[src];

    for (auto v : graph[src]) {
        if (!visited[v]) {
            dfsTipo2(graph, visited, v, minSubtree, qtdOps, k, subt, sujeira);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;

    cin >> n >> k;

    vector<long long> sujeira(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sujeira[i];
        total += sujeira[i];
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;

        graph[a].push_back(i);
    }

    vector<bool> visited(n+1, false);

    vector<long long> minInTheSubtree(n+1, 0);
    vector<long long> quantityInSubtree(n+1, 1);
    dfsBase(graph, sujeira, visited, 1, minInTheSubtree);

    vector<long long> quantidadeOperacoes(n+1, 0);
    vector<bool> visited2(n+1, false);
    dfsTipo2(graph, visited2, 1, minInTheSubtree, quantidadeOperacoes, k, 0, sujeira);

    bizurados += total;

    cout << bizurados << "\n";
}