#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    pair<int, int> ilC;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 0) {
                ilC.first = i;
                ilC.second = j;
            }
        }
    }

    int soma = 0;
    if (ilC.first > 0) {
        for (int i = ilC.first-1; i == ilC.first-1; i++) {
            for (int j = 0; j < n; j++) {
                soma += matriz[i][j];
            }
        }

    } else {
        for (int i = ilC.first+1; i == ilC.first+1; i++) {
            for (int j = 0; j < n; j++) {
                soma += matriz[i][j];
            }
        }
    }

    int somaLinha = 0;
    for (int i = ilC.first; i == ilC.first; i++) {
        for (int j = 0; j < n; j++) {
            somaLinha += matriz[i][j];
        }
    }

    int resultado = soma - somaLinha;

    cout << resultado << "\n";
    cout << ilC.first+1 << "\n";
    cout << ilC.second+1;
}