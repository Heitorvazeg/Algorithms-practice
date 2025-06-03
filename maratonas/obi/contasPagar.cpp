#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;

    int a, f, p;
    cin >> a >> f >> p;

    vector<int> vetor;
    vetor.push_back(a);
    vetor.push_back(f);
    vetor.push_back(p);
    
    sort(vetor.begin(), vetor.end());

    int soma = v;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (vetor[i] <= soma) {
            soma -= vetor[i];
            count++;
        }
    }
    cout << count;
}