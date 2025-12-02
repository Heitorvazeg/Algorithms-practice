#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> primos;
    
    for (int i = 1; i <= 3000; i++) {
        int qtdP = 0;
        for (int j = 1; j <= i; j++) {
            if (i%j == 0) qtdP++;
        }

        if (qtdP == 2) primos.insert(i);
    }

    set<int> qsPrimos;

    for (int i = 1; i <= 3000; i++) {
        int qtdP = 0;
        for (int j = 1; j <= i; j++) {
            if (primos.count(j)) {
                if (i%j == 0) qtdP++;
            }
        }

        if (qtdP == 2) qsPrimos.insert(i);
    }

    int qtPri = 0;
    for (int i = 1; i <= n; i++) {
        if (qsPrimos.count(i)) qtPri++;
    }

    cout << qtPri << "\n";
}