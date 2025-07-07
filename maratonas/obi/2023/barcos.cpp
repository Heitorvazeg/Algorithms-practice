#include <bits/stdc++.h>

using namespace std;

int dfs(int src, int destino, vector<vector<int>>& grafo, vector<bool>& visited, int n, int pass, set<int>& set) {
    if (visited[src] || src == destino) {
        return pass;
    } else {
        visited[src] = true;
    }

    for (int i = 0; i < n; i++) {
        if (grafo[src][i] != 0) {
            if (grafo[src][i] < pass) {
                if (pass == 0) {
                    pass = grafo[src][i];
                }
                pass = grafo[src][i];
            }

            pass = dfs(i, destino, grafo, visited, n, pass, set);
        }
    }
    set.insert(pass);
    return pass;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    vector<vector<int>> grafo(n, vector<int>(n, 0));
    for (int i = 0; i < b; i++) {
        int iA, iB, p;
        cin >> iA >> iB >> p;

        grafo[iA-1][iB-1] = p;
    }

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int x, y;

        cin >> x >> y;
        x--;
        y--;

        vector<bool> visited(grafo.size(), false);
        int pass = 1000001;
        set<int> set;
        pass = dfs(x, y, grafo, visited, n, pass, set);
        int max = 0;
        for (auto it = set.begin(); it != set.end(); it++) {
            cout << *it << "\n";
            if (*it > max) {
                max = *it;
            }
        }

        cout << max << "\n";
    }
}