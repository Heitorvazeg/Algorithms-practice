#include <bits/stdc++.h>
using namespace std;

//
int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    if (total % 2 != 0) {
        cout << -1 << '\n'; // impossível dividir se soma for ímpar
        return 0;
    }

    sort(a.begin(), a.end()); // começar com ordem ordenada para gerar permutações
    int alice = 0;
    int bob = 0;
    do { // Faz pelo menos uma vez
        if (is_fair_distribution(a)) {
            for (int x : a)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }
    } while (next_permutation(a.begin(), a.end())); // Gera todas as permutações

    cout << -1 << '\n'; // nenhuma ordem possível
}