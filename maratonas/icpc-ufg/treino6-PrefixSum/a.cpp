#include <bits/stdc++.h>

using namespace std;

long long query(vector<long long>& pref, int l, int r) {
    if (l == 0) return pref[r];
    return pref[r] - pref[l-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<long long> pref(n, 0);
    pref[0] = v[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + v[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        long long ans = query(pref, a, b);

        cout << ans << "\n";
    }
}