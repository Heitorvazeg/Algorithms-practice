#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        vector<int> ts(n);
        for (int i = 0; i < n; i++) {
            cin >> ts[i];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<long long>> elevators(n, vector<long long>());
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream strs(line);
            int x;
            while (strs >> x) elevators[i].push_back(x);
        }

        map<int, vector<int>> elevadores_no_andar;
        for (int i = 0; i < n; i++) {
            for (int a : elevators[i]) {
                elevadores_no_andar[a].push_back(i);
            }
        }

        vector<vector<long long>> dist(100, vector<long long>(n, INF));
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        for (int i = 0; i < n; i++) {
            if (find(elevators[i].begin(), elevators[i].end(), 0) != elevators[i].end()) {
                dist[0][i] = 0;
                pq.push({0, 0, i});
            }
        }

        while (!pq.empty()) {
            auto [d, a, e] = pq.top();
            pq.pop();

            if (d > dist[a][e]) continue;

            for (auto it : elevators[e]) {
                if (it == a) continue;
                long long custo =   ts[e] * abs(it - a);
                if (custo + d < dist[it][e]) {
                    dist[it][e] = custo + d;
                    pq.push({dist[it][e], it, e});
                }
            }

            for (int ne : elevadores_no_andar[a]) {
                if (ne == e) continue;
                long long custo = 60;
                if (d + custo < dist[a][ne]) {
                    dist[a][ne] = d + custo;
                    pq.push({dist[a][ne], a, ne});
                }
            }
        }

        long long ans = *min_element(dist[k].begin(), dist[k].end());
        if (ans == INF) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}