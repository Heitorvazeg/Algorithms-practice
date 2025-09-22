#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_set<long long> s;
    set<long long> sum;
    s.reserve(2*n);
    int j = 0;
    int i = 0;
    while (i < n) {
        while (j < n && s.find(v[j]) == s.end()) {
            s.insert(v[j]);
            long long su = 0;
            for (auto it : s) {
                su += it;
            }
            sum.insert(su);
            j++;
        }
        s.erase(v[i]);
        i++;
    }

    int c = 0;
    long long ma = 0;
    for (auto it : sum) {
        if (c == k) break;
        ma = max(ma, it);
        c++;
    }

    cout << ma << "\n";
}