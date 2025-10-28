#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

void Floyd(vector<vector<long long>>& dist, int n) {
    for (int k = 1; k <= n; k++) {
        dist[k][k] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;    
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
            dist[b][a] = c;
        }

    }

    Floyd(dist, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] == INF) {cout << -1 << "\n"; continue;}
        cout << dist[a][b] << "\n";
    }
}