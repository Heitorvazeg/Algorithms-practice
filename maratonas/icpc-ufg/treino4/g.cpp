#include <bits/stdc++.h>

using namespace std;

int mini = INT_MAX;

void solve(vector<long long> origem, int it, int xorR, int orR) {
    if (it == (int)origem.size()) {
        mini = min(mini, xorR^orR);
        return;
    }

    solve(origem, it+1, xorR, origem[it] | orR);
    solve(origem, it+1, xorR ^ orR, origem[it]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int x = 0;
    int o = v[0];
    solve(v, 1, x, o);

    cout << mini << "\n";
}