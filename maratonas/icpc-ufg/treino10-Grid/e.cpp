#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};


bool check(int x, int y, int n, int m, int it) {
    if (x+dx[it] < 0 || x+dx[it] >= n) {
        return false;

    } else if (y+dy[it] < 0 || y+dy[it] >= m) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> fila;
    int rooms = 0;
    for (int i = 0; i < n*m; i++) {
        if (visited[i/m][i%m]) continue;
        if (grid[i/m][i%m] == '#') continue;
        rooms++;
        visited[i/m][i%m] = true;
        fila.push({i/m, i%m});
        while (!fila.empty()) {
            auto [x, y] = fila.front();
            fila.pop();

            for (int i = 0; i < 4; i++) {
                if (!check(x, y, n, m, i)) continue;
                if (grid[x+dx[i]][y+dy[i]] == '#') continue;
                if (visited[x+dx[i]][y+dy[i]]) continue;

                fila.push({x+dx[i], y+dy[i]});
                visited[x+dx[i]][y+dy[i]] = true;
            }
        }
    }

    cout << rooms << "\n";
}