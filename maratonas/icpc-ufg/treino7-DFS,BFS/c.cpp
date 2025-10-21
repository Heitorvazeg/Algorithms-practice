#include <bits/stdc++.h>

using namespace std;

queue<int> fila;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    dist[0] = 1;
    vector<int> pai(n, -1);
    pai[0] = 0;

    fila.push(0);
    visited[0] = true;
    while (!fila.empty()) {
        int top = fila.front();
        fila.pop();

        for (auto it : graph[top]) {
            if (!visited[it]) {
                visited[it] = true;
                fila.push(it);
                pai[it] = top;
                dist[it] = dist[top] + 1;
            }
        }
    }

    vector<int> ans;
    
    if (pai[n-1] == -1) cout << "IMPOSSIBLE" << "\n";
    else {
        cout << dist[n-1] << "\n";
        int it = n-1;
        vector<int> ansV;
        while (pai[it] != it) {
            ansV.push_back(it+1);
            it = pai[it];
        }
        ansV.push_back(it+1);

        for (int i = (int)ansV.size()-1; i >= 0; i--) {
            cout << ansV[i] << " ";
        }

        cout << "\n";
    }
}