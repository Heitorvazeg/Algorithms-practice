#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int y, k;
    cin >> y >> k;
    int posicao = 1;

    for (int i = 0; i < k; i++) {
        int g = gcd(y, posicao);
        posicao += g;

        if (g == y) {
            posicao += (k-i-1)*y;
            break;
        }
    }

    cout << posicao;
}
