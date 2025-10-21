#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    unsigned long long t;
    cin >> n >> t;

    vector<long long> v(n, 0);
    long long mi = 10000000000;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mi = min(mi, v[i]);
    } 

    int eS = 1;
    mi = mi * t;
    sort(v.begin(), v.end());
    long long ans = mi;
    bool valid = false;
    while (eS <= mi && !valid) {
        long long m = eS + (mi + eS) / 2;
        
        unsigned long long sum = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            sum += m / v[i];
        }

        if (sum >= t) {
            if (sum == t) {
                ans = m;
                valid = true;
                break;
            }
            mi = m - 1;
            ans = m;
        
        } else {
            eS = m + 1;
        }
    }

    cout << ans << "\n";
}