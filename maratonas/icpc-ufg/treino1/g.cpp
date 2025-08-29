#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != i+1) {
            ans = i+1;
        }
    }
    cout << ans;
}