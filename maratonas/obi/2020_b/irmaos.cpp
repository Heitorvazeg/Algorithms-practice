#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;

    cin >> n >> m;

    if (n < m) {
        int aux = n;
        n = m;
        m = aux;
    }

    int r = n - m;

    int resposta = n + r;
    cout << resposta;
}