#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, int>>> graph(n+1, vector<pair<long long, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    vector<pair<int, int>> trainR;
    for (int i = 0; i < k; i++) {
        int f, e;
        cin >> f >> e;
        trainR.push_back({e, f});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n+1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto it : graph[u]) {
            if (it.first + d < dist[it.second]) {
                dist[it.second] = it.first + d;
                pq.push({dist[it.second], it.second});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < k; i++) {
        if (dist[trainR[i].second] <= trainR[i].first) {
            count++;
        }
    }

    cout << count << "\n";
}