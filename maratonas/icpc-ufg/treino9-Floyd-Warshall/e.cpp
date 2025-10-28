#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max()/4;

void Floyd(vector<vector<long long>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        dist[k][k] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
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
        int r;
        cin >> r;

        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int j = 0; j < r; j++) {
            int a, b;
            cin >> a >> b;
            dist[a][b] = 1;
            dist[b][a] = 1;
        }

        int start, end;
        cin >> start >> end;

        Floyd(dist, n);

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            ans = max(ans, (dist[start][j]+dist[j][end]));
        }

        cout << "Case " << i+1 << ": " << ans << "\n";
    }
}