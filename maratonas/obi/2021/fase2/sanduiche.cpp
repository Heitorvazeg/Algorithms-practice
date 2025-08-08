#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> nP;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nP.push_back({a, b});
    }

    if (m == 0) {
        cout << pow(2, n)-1;

    } else {
        int ans = (pow(2, n)-1)-(m+1);

        cout << ans;
    }
}