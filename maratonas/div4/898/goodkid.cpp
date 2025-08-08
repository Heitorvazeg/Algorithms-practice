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
        vector<int> v(n);

        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        sort(v.begin(), v.end());
        v[0]++;

        long long ans = 1;
        for (int j = 0; j < n; j++) {
            ans *= v[j];
        }
        cout << ans << "\n";
    }
}