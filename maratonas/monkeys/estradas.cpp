#include <bits/stdc++.h>

using namespace std;

int dfs(vector<bool>& visited, vector<vector<int>>& grafo, int src, int n, int dia) {
    int count = 1;
    if (visited[src]) {
        return count;
    } else {
        visited[src] = true;
    }

    for (int i = 0; i < n; i++) {
        if (grafo[src][i] != 0 && !visited[i]) {
            if (dia >= grafo[src][i] && !visited[i] && dia >= grafo[src][i]) {
                count += dfs(visited, grafo, i, n, dia);
            }
        } 
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grafo(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int uj, vj, dj;
        cin >> uj >> vj >> dj;
        uj--;
        vj--;

        grafo[uj][vj] = dj;
        grafo[vj][uj] = dj;
    }

    for (int i = 0; i < q; i++) {
        int dia;
        cin >> dia;

        vector<bool> visited(grafo.size(), false);
        int count = dfs(visited, grafo, 0, n, dia);
        cout << count << "\n";
    }
}