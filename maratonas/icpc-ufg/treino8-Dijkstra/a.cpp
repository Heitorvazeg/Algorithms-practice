#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n+1, vector<pair<int, long long>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pair<int, int> p;
        p.first = b;
        p.second = c;
        graph[a].push_back(p);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> filaP;
    vector<long long> dist(n+1, INF);
    pair<long long, int> p1;
    p1.first = 0;
    p1.second = 1;
    dist[1] = 0;
    filaP.push(p1);

    while(!filaP.empty()) {
        auto [distAtual, no] = filaP.top();
        filaP.pop();

        if (distAtual > dist[no]) continue;

        for (auto it : graph[no]) {
            if (dist[no] + it.second < dist[it.first]) {
                dist[it.first] = dist[no] + it.second;
                filaP.push({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}