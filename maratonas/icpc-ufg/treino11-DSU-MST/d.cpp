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

    vector<tuple<long long, int, int>> edges(m);
    make_set(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        edges[i] = {c, a, b};
    }


    sort(edges.begin(), edges.end());

    long long sum = 0;
    vector<int> rank(n, 0);
    for (int i = 0; i < m; i++) {
        auto [wei, a, b] = edges[i];
        if (find_f(a) == find_f(b)) continue;

        union_f(a, b, rank);
        sum += wei;
    }

    for (int i = 0; i < (int)parent.size()-1; i++) {
        if (find_f(parent[i]) != find_f(parent[i+1])) {
            cout << "IMPOSSIBLE" << "\n";
            return 0;
        }
    }

    cout << sum << "\n";

    cout << "\n";
}