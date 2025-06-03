#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    int a, b;
    cin >> a;
    cin >> b;

    int soma = a + b;

    int idade = m - soma;
    int max = 0;

    int vetor[3] = {a, b, idade};
    for (int i = 0; i < 3; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    cout << max;
}