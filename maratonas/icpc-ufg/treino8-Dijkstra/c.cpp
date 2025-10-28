#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> graph(n+1, vector<long long>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> teams(n+1, 1);

    queue<long long> fila;
    vector<bool> visited(n+1, false);
    fila.push(1);
    visited[1] = true;

    while(!fila.empty()) {
        long long top = fila.front();
        fila.pop();

        for (auto it : graph[top]) {
            if (!visited[it]) {
                visited[it] = true;
                fila.push(it);
                if (teams[top] == 1) teams[it] = 2;
            }
        } 
    }

    long long total = 0;
    long long ums = 0;
    for (int i = 1; i < (int)teams.size(); i++) {
        if (teams[i] == 1) ums++;
        total++;
    }

    long long ans = ((total - ums) * ums) - (n - 1);
    cout << ans << "\n";
}