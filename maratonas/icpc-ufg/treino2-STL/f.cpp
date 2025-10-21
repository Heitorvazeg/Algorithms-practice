#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<long long, int>> pqJovems;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pqVelhos;
    long long somaV = 0;
    long long somaJ = 0;
    for (int i = 0; i < n; i++) {
        int b;
        long long a;
        cin >> a >> b;

        if (i == 0) {
            pair<long long, int> p;
            p.first = a;
            p.second = b;
            pqJovems.push(p);
            somaJ += b;
            cout << b << "\n";
            continue;
        }

        if (a > pqJovems.top().first) {
            if (pqVelhos.size() < pqJovems.size()) {
                pair<long long, int> maior;
                maior.first = a;
                maior.second = b;
                pqVelhos.push(maior);
                somaV += maior.second;
                cout << abs(somaJ - somaV) << "\n";
                continue;
            } else if (a < pqVelhos.top().first) {
                pair<long long, int> menor;
                menor.first = a;
                menor.second = b;
                pqJovems.push(menor);
                somaJ += menor.second;
                cout << abs(somaJ - somaV) << "\n";
                continue;
            }

            pair<long long, int> menor = pqVelhos.top(); 
            pqVelhos.pop();
            somaV -= menor.second;
            pqJovems.push(menor);
            somaJ += menor.second;

            pair<long long, int> maior;
            maior.first = a;
            maior.second = b;
            pqVelhos.push(maior);
            somaV += maior.second;

        } else {
            if (pqJovems.size() < pqVelhos.size()) {
                pair<long long, int> menor;
                menor.first = a;
                menor.second = b;
                pqJovems.push(menor);
                somaJ += menor.second;
                cout << abs(somaJ - somaV) << "\n";
                continue;
            } else if (pqJovems.size() == pqVelhos.size()){
                pair<long long, int> menor;
                menor.first = a;
                menor.second = b;
                pqJovems.push(menor);
                somaJ += menor.second;
                cout << abs(somaJ - somaV) << "\n";
                continue;
            }

            pair<long long, int> maior = pqJovems.top();
            pqJovems.pop();
            somaJ -= maior.second;

            pair<long long, int> menor;
            menor.first = a;
            menor.second = b;
            pqJovems.push(menor);
            somaJ += menor.second;
            pqVelhos.push(maior);
            somaV += maior.second;
        }

        cout << abs(somaJ - somaV) << "\n";
    }
}