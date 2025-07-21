#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    int min = 1000001;
    pair<int, int> Pmin;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < min) {
                min = matriz[i][j];
                Pmin.first = i;
                Pmin.second = j;
            }
        }
    }

    if (Pmin.first == 0 && Pmin.second == n-1) {
        cout << 1;

    } else if (Pmin.first == n-1 && Pmin.second == n-1) {
        cout << 2;

    } else if (Pmin.first == n-1 && Pmin.second == 0) {
        cout << 3;

    } else {
        cout << 0;
    }
}