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

    unordered_map<long long, int> m;
    for (int i = 0; i < n; i++) {
        if (m.count(v[i])) {
            m[v[i]]++;

        } else {
            m[v[i]] = 1;
        }
    }

    vector<int> it;
    for (int i = 0; i < n; i++) {
        if (m[v[i]] != v[i]) {
            m[v[i]]--;
            continue;
        }
        it.push_back(v[i]);
    }

    cout << n - (int)it.size();
