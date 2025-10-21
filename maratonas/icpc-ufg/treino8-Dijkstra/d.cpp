#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(vector<vector<int>>& tree, int src, int ant, int dist) {
    pair<int, int> r = {dist, src};
    for (auto it : tree[src]) {
        if (it == ant) continue;
        r = max(r, dfs(tree, it, src, dist + 1));
    }
    return r;
}

void bfs(vector<vector<int>>& graph, int src, vector<bool>& visited, queue<int>& fila, vector<long long>& dist) {
    fila.push(src);
    visited[src] = true;
    while(!fila.empty()) {
        int top = fila.front();
        fila.pop();

        for (auto it : graph[top]) {
            if (!visited[it]){
                visited[it] = true;
                fila.push(it);
                dist[it] = dist[top] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto [di, src] = dfs(graph, 1, -1, 0);
    auto [di2, src2] = dfs(graph, src, -1, 0);

    vector<long long> dist1(n+1, 0);
    vector<bool> visited(n+1, false);
    queue<int> fila;
    bfs(graph, src, visited, fila, dist1);

    vector<long long> dist2(n+1, 0);
    vector<bool> visited2(n+1, false);
    queue<int> fila2;
    bfs(graph, src2, visited2, fila2, dist2);

    for (int i = 1; i <= n; i++) {
        int m = max(dist1[i], dist2[i]);
        cout << m << " ";
    }

    cout << "\n";
}