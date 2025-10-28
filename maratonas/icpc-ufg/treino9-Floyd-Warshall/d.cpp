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

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> dist[j+1][k+1];
            }
        }

        int r;
        cin >> r;

        Floyd(dist, n);

        long long di = 0;
        for (int j = 0; j < r; j++) {
            int a, b;
            cin >> a >> b;

            di += dist[a][b];
        }

        cout << "Case #" << i+1 << ": " << di << "\n";
    }
}