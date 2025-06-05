#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int contarVizinhos(vector<vector<char>>& matriz, int i, int j, int n) {
    int vivos = 0;
    for (int z = 0; z < 8; z++) {
        int ni = i + dx[z];
        int nj = j + dy[z];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            if (matriz[ni][nj] == '1') {
                vivos++;
            }
        }
    }
    return vivos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<char>> matriz(n, vector<char>(n, '0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        vector<vector<int>> matrizRes(n, vector<int>(n, '0'));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int vivos = contarVizinhos(matriz, j, k, n);
                if (matriz[j][k] == '0' && vivos == 3) matrizRes[j][k] = '1';
                if (matriz[j][k] == '1' && (vivos == 2 || vivos == 3)) matrizRes[j][k] = '1';
                if (matriz[j][k] == '1' && vivos < 2) matrizRes[j][k] = '0';
                if (matriz[j][k] == '1' && vivos > 3) matrizRes[j][k] = '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = matrizRes[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j];
        }
        cout << "\n";
    }
}