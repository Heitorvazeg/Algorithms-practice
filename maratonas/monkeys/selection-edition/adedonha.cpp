#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> map;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        map[s] = 0;
    }


    vector<pair<string, string>> nomes(n);
    for (int i = 0; i < n; i++) {
        cin >> nomes[i].first;
        cin >> nomes[i].second;
    }

    for (int i = 0; i < n; i++) {
        if (map.count(nomes[i].second)) map[nomes[i].second]++;
    }

    for (int i = 0; i < n; i++) {
        cout << nomes[i].first << " ";
        int num;
        if (map[nomes[i].second] > 1) {
            num = 5;
        } else if (map[nomes[i].second] == 1) {
            num = 10;
        } else {
            num = 0;
        }
        cout << num << "\n";
    }
}