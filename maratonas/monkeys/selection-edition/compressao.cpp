#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> mR(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        mR[i][0] = grid[i][0];
        for (int j = 1; j < m; j++) {
            if (j < k) {
                mR[i][j] = grid[i][j]-grid[i][j-1];

            } else if (j < m) {
                int sum = 0;
                for (int l = 1; l < k; l++) {
                    sum += mR[i][j-l];
                }
                mR[i][j] = grid[i][j]-sum;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mR[i][j] << " ";
        }
        cout << "\n";
    }
}