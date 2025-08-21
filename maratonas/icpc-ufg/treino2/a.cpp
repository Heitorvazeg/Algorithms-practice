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

    set<long long> s;
    int dist = 0;
    for (int i = 0; i < n; i++) {
        s.insert(v[i]);
    }
    set<long long>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        dist++;
    }
    cout << dist;
}