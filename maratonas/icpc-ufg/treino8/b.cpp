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
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<long long> dist(n+1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> parent(n+1, -1);
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto [dis, no] = pq.top();
        pq.pop();

        if (dis > dist[no]) continue;

        for (auto it : graph[no]) {
            if (it.second + dist[no] < dist[it.first]) {
                dist[it.first] = it.second + dist[no];
                parent[it.first] = no;
                pq.push({dist[it.first], it.first});
            }
        }
    }


    if (dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<long long> ans;
    int a = n;
    while (a > 0) {
        ans.push_back(a);
        a = parent[a];
    }

    for (int i = (int)ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    cout << "\n";
}