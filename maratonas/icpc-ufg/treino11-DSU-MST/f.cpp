#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> parent;

int find_f(int a) {
    if (a != parent[a]) {
        parent[a] = find_f(parent[a]);
    }

    return parent[a];
}

void union_f(int a, int b, vector<int>& qtd, vector<int>& ma, vector<int>& mi) {
    int dA = find_f(a);
    int dB = find_f(b);

    if (qtd[dB] > qtd[dA]) {
        parent[dA] = dB;
        qtd[dB] += qtd[dA];
        if (ma[dB] < ma[dA]) ma[dB] = ma[dA];
        if (mi[dB] > mi[dA]) mi[dB] = mi[dA];

    } else {
        parent[dB] = dA;
        qtd[dA] += qtd[dB];
        if (ma[dA] < ma[dB]) ma[dA] = ma[dB];
        if (mi[dA] > mi[dB]) mi[dA] = mi[dB];
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

    vector<int> qtd(n, 1);
    vector<int> ma(n);
    vector<int> mi(n);
    for (int i = 0; i < n; i++) {
        ma[i] = i;
        mi[i] = i;
    }

    make_set(n);

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (s == "union") {
            int a, b;
            cin >> a >> b;

            if (find_f(a-1) != find_f(b-1)) {
                union_f(a-1, b-1, qtd, ma, mi);
            }

        } else {
            int c;
            cin >> c;

            int a = find_f(c-1);

            cout << mi[a]+1 << " " << ma[a]+1 << " " << qtd[a] << "\n";
        }
    }
}