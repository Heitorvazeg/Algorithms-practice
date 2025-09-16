#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> fr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> fr[i][j];
        }
    }

    int total = 0;
    for (int i = 0; i < m; i++) {
        int ma = 0;
        for (int j = 0; j < n; j++) {
            if (fr[j][i] > ma) ma = fr[j][i];
        }
        total += ma;
    }

    cout << total << "\n";
}