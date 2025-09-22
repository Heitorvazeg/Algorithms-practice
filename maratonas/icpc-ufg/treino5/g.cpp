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
        pair<long long, int> p;
        cin >> p.first;
        p.second = i;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end());
    vector<int> ans(3, 0);
    bool res = false;
    for (int i = 0; i < n && !res; i++) {
        int e = 0;
        int d = (int)v.size()-1;
        long long sum = 0;
        while (e <= d) {
            if (e == i) e++;
            else if (d == i) d--;

            sum = (v[e].first + v[i].first + v[d].first);
            if (sum == x) {
                ans[0] = v[e].second;
                ans[1] = v[d].second;
                ans[2] = v[i].second;
                res = true;
                break;
            
            } else if (sum < x) e++;
            else {
                d--;
            }
        }        
    }
    set<int> se;
    for (int i = 0; i < 3; i++) {
        se.insert(ans[i]);
    }
    
    if ((int)se.size() != 3) {
        cout << "IMPOSSIBLE" << "\n";

    } else {
        for (int i = 0; i < 3; i++) {
            cout << ans[i]+1 << " ";
        }
        cout << "\n";
    }
}