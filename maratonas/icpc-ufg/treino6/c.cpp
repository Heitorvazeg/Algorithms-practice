#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long> pref(n+1, 0);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        if (pref[i] < 0) {
            pref[i+1] = v[i];

        } else {
            pref[i+1] = pref[i] + v[i];
        }
    }

    long long m = -10000000000;

    for (int i = 1; i <= n; i++) {
        if (pref[i] > m) m = pref[i];
    }

    cout << m << "\n";
}