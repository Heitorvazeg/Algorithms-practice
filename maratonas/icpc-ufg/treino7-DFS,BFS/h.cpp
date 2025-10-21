#include <bits/stdc++.h>

using namespace std;

int ans = 0;
bool found = false;
pair<int, int> p;

pair<int, int> dfs(vector<vector<int>>& tree, int src, int ant, int dist) {
    pair<int, int> r = {dist, src};
    for (auto it : tree[src]) {
        if (it == ant) continue;
        r = max(r, dfs(tree, it, src, dist + 1));
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    auto p1 = dfs(tree, 1, -1, 0);
    auto p2 = dfs(tree, p1.second, -1, 0);

    cout << p2.first << "\n";
}