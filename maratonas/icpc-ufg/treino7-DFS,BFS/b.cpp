#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        int a = v[i];
        int b = v[a];
        int c = v[b];

        if (i == c) {cout << "YES" << "\n"; return 0;}
    }

    cout << "NO" << "\n";
}