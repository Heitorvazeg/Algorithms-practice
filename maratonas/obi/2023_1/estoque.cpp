#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> m >> n;

    vector<vector<int>> matriz(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }
    int p;
    cin >> p;
    int a, b;

    int resultado = 0;

    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        a--;
        b--;

        if (matriz[a][b] != 0) {
            matriz[a][b]--;
            resultado++;
        }
    }

    cout << resultado;
}