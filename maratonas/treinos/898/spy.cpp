#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> v(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        unordered_map<int, pair<int, int>> m;
        for (int j = 0; j < n; j++) {
            if (!m.count(v[j])) {
                pair<int, int> p;
                p.first = 1;
                p.second = j;
                m[v[j]] = p;

            } else {
                m[v[j]].first++;
            }
        }

        for (auto it : m) {
            if (it.second.first == 1) cout << it.second.second+1 << "\n";
        }
    }
}