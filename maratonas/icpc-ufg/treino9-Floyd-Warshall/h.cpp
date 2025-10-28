#include <bits/stdc++.h>

using namespace std;

void FloydDynamic(vector<vector<long long>>& dist, int n, int a, int u, int w) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = min({dist[i][j], dist[i][a] + w + dist[u][j], dist[i][u] + w + dist[a][j]});
        }
    }
}

long long countSho(vector<vector<long long>>& dist, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) continue;
            sum += dist[i][j];
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<vector<long long>> dist(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (dist[a-1][b-1] > c) {
            dist[a-1][b-1] = c;
            dist[b-1][a-1] = c;
        }
        
        FloydDynamic(dist, n, a-1, b-1, c);

        long long sum = countSho(dist, n);

        cout << sum << " ";
    }

    cout << "\n";
}