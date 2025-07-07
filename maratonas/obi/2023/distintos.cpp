#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int soma = 0;
    int resultado = 0;
    vector<int> array(n, 0);
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++) {
        soma += array[i];

        if (map.count(soma - i)) {
            resultado += map[soma - n];
        }

        map[soma]++;
    }

    cout << resultado;
}