#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        if (!m.count(a)) {
            m[a] = 1;

        } else {
            m[a]++;
        }

        if (!m.count(b)) {
            m[b] = 1;

        } else {
            m[b]++;
        }
    }

    for (auto it : m) {
        if (it.second == n-1) {
            cout << "Yes" << "\n";
            return 0;
        }
    }

    cout << "No" << "\n";
}