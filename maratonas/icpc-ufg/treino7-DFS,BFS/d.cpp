#include <bits/stdc++.h>

using namespace std;

int findComp(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findComp(parent, parent[x]);
    }

    return parent[x];
}

void unionF(vector<int>& parents, int a, int b) {
    int pA = findComp(parents, a);
    int pB = findComp(parents, b);

    parents[pB] = pA;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<int> parents(n, -1);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < (int)graph.size(); i++) {
        for (int j = 0; j < (int)graph[i].size(); j++) {
            unionF(parents, i, graph[i][j]);
        }
    }

    vector<int> resps;
    for (int i = 0; i < (int)parents.size(); i++) {
        if (findComp(parents, i) == i) {
            resps.push_back(i);
        }
    }

    cout << (int)resps.size()-1 << "\n";

    for (int i = 1; i < (int)resps.size(); i++) {
        cout << resps[i-1]+1 << " " << resps[i]+1 << "\n";
    }
}