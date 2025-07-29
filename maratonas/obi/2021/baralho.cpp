#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string sequencia;
    getline(cin, sequencia);
    int seqSize = sequencia.size();

    unordered_map<char, int> map;
    map['C'] = 0;
    map['E'] = 1;
    map['U'] = 2;
    map['P'] = 3;

    vector<pair<char,vector<int>>> conjunto(4, pair<char,vector<int>>());
    conjunto[0].first = 'C';
    conjunto[1].first = 'E';
    conjunto[2].first = 'U';
    conjunto[3].first = 'P';
    for (int i = 0; i < seqSize; i+=3) {
        char naipe = sequencia[i+2];
        int carta;
        if (sequencia[i] == '0') {
            carta = sequencia[i+1] - '0';

        } else {
            char pD = sequencia[i];
            char sD = sequencia[i+1];
            string digito = to_string(pD)+to_string(sD);
            carta = stoi(digito);
        }

        conjunto[map[naipe]].second.push_back(carta);
    }

    for (int i = 0; i < 4; i++) {
        vector<int> vetor = conjunto[i].second;
        int size = vetor.size();
        unordered_map<int, int> mapAjuda;
        int ajuda = 0;
        for (int j = 0; j < size; j++) {
            if (mapAjuda.count(vetor[j])) {
                ajuda++;
                cout << "erro" << "\n";
                break;
            }
            mapAjuda[vetor[j]] = j;
        }

        if (ajuda > 0) {
            continue;
        }
        int faltantes = 13-size;
        cout << faltantes << "\n";
    }
}