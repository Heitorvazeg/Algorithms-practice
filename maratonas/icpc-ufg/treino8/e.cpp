#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    vector<vector<long long>> dist(n+1, vector<long long>(2, INF));
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d > dist[u][used]) continue;

        for (auto it : graph[u]) {
            if (d + it.first < dist[it.second][used]) {
                dist[it.second][used] = d + it.first;
                pq.push({dist[it.second][used], it.second, used});
            }

            if (used == 0 && d + it.first/2 < dist[it.second][1]) {
                dist[it.second][1] = d + it.first/2;
                pq.push({dist[it.second][1], it.second, 1});
            }
        }
    }

    cout << min(dist[n][1], dist[n][0]) << "\n";
}