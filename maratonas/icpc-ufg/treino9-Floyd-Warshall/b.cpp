#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

long long Dijk(vector<long long>& dist, vector<vector<pair<long long, int>>>& graph, int n, int m) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
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
    return dist[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        unordered_map<string, int> m;
        vector<vector<pair<long long, int>>> graph(n+1, vector<pair<long long, int>>());

        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            int p;
            cin >> p;
            m[s] = j+1;

            for (int k = 0; k < p; k++) {
                int a, b;
                cin >> a >> b;
                graph[j+1].push_back({b, a});
            }
        }

        int r;
        cin >> r;

        int used = false;
        for (int j = 0; j < r; j++) {
            string one, two;
            cin >> one >> two;

            vector<long long> dist(n+1, INF);

            if (!used) cout << Dijk(dist, graph, m[one], m[two]) << "\n";
            else cout << dist[m[one]][m[two]];
        }
    }
}