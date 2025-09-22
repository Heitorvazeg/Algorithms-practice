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

    int j = 0;
    int i = 0;
    int maxi = 0;
    set<long long> s;
    while (j < (int)v.size()) {
        while (s.count(v[j])) {
            s.erase(v[i]);
            i++;
        }

        s.insert(v[j]);
        maxi = max(maxi, (int)s.size());
        j++;
    }
    maxi = max(maxi, (int)s.size());

    cout << maxi << "\n";
}