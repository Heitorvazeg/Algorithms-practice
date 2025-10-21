#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    long long ans = 0;
    unordered_set<long long> s;
    s.reserve(2*n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && s.find(v[j]) == s.end()) {
            s.insert(v[j]);
            ++j;
        }
        ans += (j - i);
        s.erase(v[i]);
    }

    cout << ans << '\n';
    return 0;
}
