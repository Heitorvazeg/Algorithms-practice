#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> pilha;
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;

        if (valor == 0) {
            pilha.pop();

        } else {
            pilha.push(valor);
        }
    }

    int soma = 0;
    while (!pilha.empty()) {
        int numero = pilha.top();
        pilha.pop();
        soma += numero;
    }

    cout << soma;
}