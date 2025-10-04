#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<long long> pref(n+1, 0);
        pref[0] = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == 'B') {
                pref[j+1] = pref[j] + 1;

            } else {
                pref[j+1] = pref[j];
            }

        }

        long long m = 10000000000;
        for (int j = k; j < (int)pref.size(); j++) {
            long long bs = pref[j] - pref[j-k];
            if (k - bs < m) m = k - bs;
        }

        cout << m << "\n";
    }
}