#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& qtd, vector<bool>& visited, int src, int ant) {
    if (visited[src]) return;
    qtd[src] = 0;
    visited[src] = true;

    for (int i = 0; i < (int)graph[src].size(); i++) {
        if (graph[src][i] == ant) continue;
        dfs(graph, qtd, visited, graph[src][i], src);
        qtd[src] += qtd[graph[src][i]] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        graph[i].push_back(a);
        graph[a].push_back(i);
    }

    vector<int> qtd(n+1, 0);
    vector<bool> visited(n+1, false);
    dfs(graph, qtd, visited, 1, 0);

    for (int i = 1; i <= n; i++) {
        cout << qtd[i] << " ";
    }

    cout << "\n";
}