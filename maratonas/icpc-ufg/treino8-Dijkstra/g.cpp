#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    priority_queue<pair<long long, int>, 
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> pq;
    vector<vector<long long>> dist(n+1, vector<long long>());
    pq.push({0, 1});
    

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if ((int)dist[u].size() > k-1) continue;
        dist[u].push_back(d);

        for (auto it : graph[u]) {
            if ((int)dist[it.second].size() < k) {
                pq.push({d + it.first, it.second});
            }
        }
    }

    for (int i = 0; i < (int)dist[n].size(); i++) {
        cout << dist[n][i] << " ";
    }

    cout << "\n";
}