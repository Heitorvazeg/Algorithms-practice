#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<long long> pref(n+1, 0);
    pref[0] = 0;
    vector<long long> suf(n+1, 0);
    suf[(int)suf.size()-1] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = __gcd(pref[i-1], v[i-1]);
        suf[(int)suf.size()-1-i] = __gcd(suf[(int)suf.size()-i], v[(int)v.size()-i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long a = __gcd(pref[i], suf[i+1]);
        ans = max(ans, a);
    }

    cout << ans << "\n";
}