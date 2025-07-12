// Questão de Bits.

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    // Lê os números
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Conta quantos bits '1' existem em cada posição
    vector<int> bitCount(31, 0);
    for (int i = 0; i < n; i++) {
        for (int b = 0; b <= 30; b++) {
            if ((a[i] >> b) & 1)
                bitCount[b]++;
        }
    }

    // Gera a nova lista máxima possível
    vector<int> result(n, 0);   
    for (int i = 0; i < n; i++) {
        // Coloca os bits disponíveis do mais significativo para o menos
        for (int b = 30; b >= 0; b--) {
            if (bitCount[b] > 0) {
                result[i] |= (1 << b);
                bitCount[b]--;
            }
        }
    }

    for (int x : result) cout << x << ' ';
    cout << '\n';
    return 0;
}