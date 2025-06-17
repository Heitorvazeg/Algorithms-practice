#include <bits/stdc++.h>

using namespace std;

int desvendarAmigo(string s) {
    int size = s.size();
    int amigo = 0;

     if (size < 2) {
        amigo = s[0] - '0';

    } else if (size < 3) {
        char pD = s[0] - '0';
        char sD = s[1] - '0';
        string digito = to_string(pD)+to_string(sD);
        amigo = stoi(digito);

    } else if (size == 3) {
        char pD = s[0] - '0';
        char sD = s[1] - '0';
        char tD = s[2] - '0';
        string digito = to_string(pD)+to_string(sD)+to_string(tD);
        amigo = stoi(digito);
    }
    return amigo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, pair<int, int>> amigosT;
    vector<int> amigo;
    unordered_map<int, pair<int, int>> tempoResposta;
    vector<int> amigosR;

    for (int i = 0; i < n; i++) {
        int size = amigosT.size();
        string linha;
        getline(cin, linha);
        linha.replace(1, 1, "");

        if (linha[0] == 'R') {
            linha.replace(0, 1, "");
            int amigo = desvendarAmigo(linha);

            amigosT[amigo].first = amigo;
            amigosT[amigo].second = 0;
            amigos.push_back(amigo);

        } else if (linha[0] == 'T') {
            linha.replace(0, 1, "");
            int tempo = linha[1] - '0';

            for (int i = 0; i < size; i++) {
                amigosT[amigos[i]].second += tempo-2;
            }

        } else if (linha[0] == 'E') {
            linha.replace(0, 1, "");
            int amigoEnv = desvendarAmigo(linha);
            tempoResposta[amigoEnv].first = amigoEnv;
            tempoResposta[amigoEnv].second = amigosT[amigoEnv].second;
            amigosR.push_back(amigoEnv);
            amigosT.erase(amigoEnv);

            int amigS = amigos.size();
            for (int i = 0; i < amigS; i++) {
                if (amigos[i] == amigoEnv) {
                    amigos.erase(amigos.begin() + i);
                }
            }
        }

        for (int i = 0; i < size; i++) {
            amigosT[amigos[i]].second += 1;
        }
    }
    int size = tempoResposta.size();
    for (int i = 0; i < size; i++) {
        int amigoR = tempoResposta[amigosR[i]].first;
        int tempoR = tempoResposta[amigosR[i]].second;
        cout << amigoR << " " << tempoR << "\n";
    }
}