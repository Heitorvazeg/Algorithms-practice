#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parent;

int find_f(int a) {
    if (a != parent[a]) {
        parent[a] = find_f(parent[a]);
    }

    return parent[a];
}

int ma = 1;

void union_f(int a, int b, vector<int>& rank, vector<int>& qtd) {
    int dA = find_f(a);
    int dB = find_f(b);

    if (rank[dA] > rank[dB]) {
        parent[dB] = dA;
        qtd[dA] += qtd[dB];
        ma = max(ma, qtd[dA]);

    } else {
        parent[dA] = dB;
        qtd[dB] += qtd[dA];
        ma = max(ma, qtd[dB]);
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

    make_set(n);
    vector<int> qtd(n, 1);
    vector<int> rank(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (find_f(a-1) == find_f(b-1)) continue;

        union_f(a-1, b-1, rank, qtd);
    }

    cout << ma << "\n";
}