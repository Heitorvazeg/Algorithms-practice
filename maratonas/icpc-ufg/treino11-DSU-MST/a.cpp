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

    int n, q;
    cin >> n >> q;

    vector<int> rank(n, 0);
    make_set(n);

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            union_f(u, v, rank);

        } else {
            if (find_f(u) == find_f(v)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}