#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parent;

int find_f(int a) {
    if (a != parent[a]) {
        parent[a] = find_f(parent[a]);
    }

    return parent[a];
}

void union_f(int a, int b, vector<int>& rank) {
    int dA = find_f(a);
    int dB = find_f(b);

    if (rank[dA] > rank[dB]) {
        parent[dB] = dA;

    } else {
        parent[dA] = dB;
    }

    if (rank[dA] == rank[dB]) {
        rank[dB]++;
    }
}

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<tuple<long long, int, int, int>> edges(m);
    make_set(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        edges[i] = {c, a, b, i};
    }


    sort(edges.begin(), edges.end());

    long long sum = 0;
    vector<int> indexes;
    vector<int> rank(n, 0);
    for (int i = 0; i < m; i++) {
        if ((int)indexes.size() == n-1) break;

        auto [wei, a, b, ind] = edges[i];
        if (find_f(a) == find_f(b)) continue;

        union_f(a, b, rank);
        indexes.push_back(ind);
        sum += wei;
    }

    cout << sum << "\n";
    for (int i = 0; i < (int)indexes.size(); i++) {
        cout << indexes[i] << " ";
    }

    cout << "\n";
}