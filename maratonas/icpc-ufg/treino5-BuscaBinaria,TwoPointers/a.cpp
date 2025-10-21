#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long x;
    cin >> n >> x;
        
    vector<pair<long long, int>> v;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pair<long long, int> p;
        p.first = a;
        p.second = i;
        v.push_back(p);
    }

    int i = 0;
    int j = (int)v.size()-1;
    pair<int, int> ans;
    bool made = false;
    sort(v.begin(), v.end());
    while (i < j) {
        if (v[i].first + v[j].first == x) {
            ans.first = v[j].second;
            ans.second = v[i].second;
            made = true;
            break;
        }

        if (v[i].first + v[j].first < x) {
            i++;

        } else {
            j--;
        }
    }
    if (!made) cout << "IMPOSSIBLE" << "\n";
    else cout << ans.first+1 << " " << ans.second+1 << "\n";
}