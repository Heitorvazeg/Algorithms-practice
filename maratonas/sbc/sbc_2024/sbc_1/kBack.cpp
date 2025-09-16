#include <bits/stdc++.h>
using namespace std;

vector<int> a;           // vetor original
vector<int> permutacao;  // permutação sendo formada
vector<bool> usado;      // marca os elementos já usados

bool is_fair_distribution(const vector<int>& a) {
    int alice = 0, bob = 0;
    for (int candy : a) {
        if (alice <= bob)
            alice += candy;
        else
            bob += candy;
    }
    return alice == bob;
}

bool found = false;

void backtrack(int n, int alice, int bob, int reman) {
    if (found) return; // Para td se achar uma válida.
    if ((int)permutacao.size() == n && is_fair_distribution(permutacao)) {
        // permutação completa
        for (int x : permutacao) {
            cout << x << " ";
        }
        cout << '\n';
        
        found = true;

        return;
    }

    if (abs(alice - bob) > reman) return;
    int lastTried = INT_MIN; // Lógica para pular duplicatas. Só funciona com Sort no vetor
    for (int i = 0; i < n; i++) {
        if (usado[i]) continue; // já usei esse número

        if (a[i] == lastTried) continue;

        // Escolher o elemento a[i]
        usado[i] = true;
        permutacao.push_back(a[i]);

        backtrack(n, ); // recursão

        // Desfazer a escolha
        usado[i] = false;
        permutacao.pop_back();

        lastTried = a[i];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }

    usado.assign(n, false);
    sort(a.begin(), a.end());

    backtrack(n);
    if (!found) cout << -1;
    return 0;
}