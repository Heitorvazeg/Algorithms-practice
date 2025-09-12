#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parents;

int findComp(int x) {
    if (parents[x] != x) {
        parents[x] = findComp(parents[x]);
    }

    return parents[x];
}

void unionF(int a, int b) {
    int cA = findComp(a);
    int cB = findComp(b);

    parents[cB] = cA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n+1, 0);

    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        
        if (findComp(a) == findComp(b)) continue;
        unionF(a, b);
    }

    set<int> s;
    for (auto it : parents) {
        int aux = findComp(it.second);
        s.insert(aux);
    }

    cout << s.size() << "\n";
}