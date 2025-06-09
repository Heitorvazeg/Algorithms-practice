#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s;

    cin >> n >> m >> s;

    int resultado;
    int max = 0;
    for (int i = n; i <= m; i++) {
        resultado = 0;
        string numeros = to_string(i);
        int use = numeros.size();
        for (int i = 0; i < use; i++) {
            int numero = numeros[i] - '0';
            resultado += numero;
        }
        if (resultado == s && i > max) {
            max = i;
        }
    }

    if (max > 0) cout << max;
    if (max == 0) cout << -1;
}