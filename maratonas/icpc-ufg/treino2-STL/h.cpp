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
    sort(v.begin(), v.end());

    long long med = v[(int)v.size()/2];
    
    long long c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != med) {
            c += abs(v[i] - med);
        }
    }

    cout << c;
}