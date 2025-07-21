#include <bits/stdc++.h> // Nao deu :(
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

void backtrack(int n) {
    if ((int)permutacao.size() == n && is_fair_distribution(permutacao)) {
        // permutação completa
        for (int x : permutacao) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (usado[i]) continue; // já usei esse número

        // Escolher o elemento a[i]
        usado[i] = true;
        permutacao.push_back(a[i]);

        backtrack(n); // recursão

        // Desfazer a escolha
        usado[i] = false;
        permutacao.pop_back();
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

    backtrack(n);
    return 0;
}
