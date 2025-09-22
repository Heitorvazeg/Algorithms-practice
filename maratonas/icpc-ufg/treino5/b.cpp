#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int q;
    cin >> q;
    vector<long long> moni(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> moni[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) {
        auto ans = upper_bound(v.begin(), v.end(), moni[i]);
        cout << ans-v.begin() << "\n";
    }
}