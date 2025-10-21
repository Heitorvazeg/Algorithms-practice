#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> teams(n+1, 0);
    queue<int> fila;
    vector<bool> visited(n+1, false);
    for (int j = 1; j <= n; j++) {
        if (visited[j]) continue;
        fila.push(j);
        teams[j] = 1;
        visited[j] = true;
        while (!fila.empty()) {
            int top = fila.front();
            fila.pop();

            for (auto it : graph[top]) {
                if (teams[top] == teams[it]) {cout << "IMPOSSIBLE" << "\n"; return 0;}
                if (visited[it] == true) continue;
                if (teams[top] == 1) teams[it] = 2;
                else teams[it] = 1;
                visited[it] = true;
                fila.push(it);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }

    cout << "\n";
}