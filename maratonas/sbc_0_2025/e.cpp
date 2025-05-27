#include <bits/stdc++.h>

using namespace std;

bool ehPrimo(int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int y, k;
    cin >> y >> k;
    int posicao = 1;
    int ok = ehPrimo(y);

    if (ok) {
        for (int i = 1; i < k-1; i++) {
            posicao++;
        }
    }
    for (int i = 0; i < k; i++) {
        if (ok) {
            i = y;
        }
        int g = gcd(y, posicao);
        posicao += g;

        if (g == y) {
            posicao += (k-i-1)*y;
            break;
        }
    }

    cout << posicao;
}

bool ehPrimo(int x) {
    if (x == 1) return false;
    if (x == 2) return true;

    if (x % 2 == 0) return false;

    int raiz = sqrt(x);
    for (int i = 3; i < raiz; i++) {
        if (x%i == 0) return false;
    }
    return true;
}