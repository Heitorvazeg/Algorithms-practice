#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> chuva(n);
    for (int i = 0; i < n; i++) {
        cin >> chuva[i];
    }

    unordered_map<long long, long long> map;
    map[0] = 1;
    long long soma = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        soma += chuva[i];

        if (map.count(soma - s)) {
            count += map[soma-s];
        }
        map[soma]++;
    }

    cout << count;
}