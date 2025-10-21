#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i].first = a;
    }
    
    vector<pair<int, int>> vAns = v;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int s = v.size()-1;

    unordered_map<int, int> m;
    for (int i = 0; i <= s; i++) {
        if (m.count(v[i].first)) m[v[i].first]++;
        else m[v[i].first] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (m.count(v[i].first)) {
            v[i].second = m[v[i].first];
        }
    }

    unordered_map<int, long> m2;
    m2[0] = 0;
    int ant = 0;
    long long antC = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].first == v[ant].first) {
            m2[v[i].first] = antC;

        } else {
            antC = ((long long)v[i-1].first * (long long)v[i-1].second) + antC;
            m2[v[i].first] = antC;
        }
        ant = i;
    }

    for (int i = 0; i < n; i++) {
        cout << m2[vAns[i].first] << " ";
    }
}