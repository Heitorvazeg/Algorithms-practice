#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s, t;
    cin >> s >> t;

    vector<vector<int>> grafo(s, vector<int>(s, 0));

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a-1][b-1] = 1;
        grafo[b-1][a-1] = 1;
    }

    int p;
    cin >> p;
    int resultado = 0;

    for (int i = 0; i < p; i++) {
        int auxiliar = 0;
        int numeroSaloes;
        cin >> numeroSaloes;
        vector<int> passeio(numeroSaloes);
        for (int j = 0; j < numeroSaloes; j++) {
            cin >> passeio[j];
            passeio[j]--;
        }

        bool valido = true;
        for (int k = 1; k < numeroSaloes; k++) {
            if (grafo[passeio[k-1]][passeio[k]] != 1) {
                valido = false; 
                break;
            }
            if (valido && k == numeroSaloes-1) {
                auxiliar++;
                resultado += auxiliar;
            }
        }
    }

    cout << resultado;
}