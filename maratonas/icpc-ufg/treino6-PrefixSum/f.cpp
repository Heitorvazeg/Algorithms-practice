#include <bits/stdc++.h>

using namespace std;

long long solver(vector<long long>& v, vector<long long>& pref, int k) {
    long long ans = 0;
    for (int x = 0; x <= k; x++) {
        int y = k - x;
        int left = 2 * x;
        int right = (int)v.size() - y;
        if (left <= right) {
            long long sum = pref[right] - pref[left];
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        vector<long long> v(n, 0);
        for (int j = 0; j < n; j++) cin >> v[j];

        vector<long long> pref(n+1, 0);
        pref[0] = 0;
        sort(v.begin(), v.end());
        for (int j = 1; j <= n; j++) pref[j] = pref[j-1] + v[j-1];

        long long ans = solver(v, pref, k);

        cout << ans << "\n";
    }
}