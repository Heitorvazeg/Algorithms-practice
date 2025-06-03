#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long vetor[n];
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }

    unordered_map<long long, long long> freq;
    freq[0] = 1;
    long long soma = 0; 
    long long resultado = 0;

    for (int i = 0; i < n; i++) {
        soma += vetor[i];

        if (freq.count(soma - k)) {
            resultado += freq[soma - k];
        }

        freq[soma]++;
    }

    cout << resultado << '\n';
}