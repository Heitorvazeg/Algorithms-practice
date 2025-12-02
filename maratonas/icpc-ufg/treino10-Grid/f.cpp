#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

tuple<bool, char> check(vector<vector<char>>& grid, int x, int y, int n, int m, int it) {
    if (x+dx[it] < 0 || x+dx[it] >= n) {
        return {false, '#'};

    } else if (y+dy[it] < 0 || y+dy[it] >= m) {
        return {false, '#'};
    }

    return {true, grid[x+dx[it]][y+dy[it]]};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    pair<int, int> ori;
    pair<int, int> des;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                ori.first = i;
                ori.second = j;
            } else if (grid[i][j] == 'B') {
                des.first = i;
                des.second = j;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> fila;
    vector<pair<int, int>> parent(n, -1);
    fila.push({ori.first, ori.second});
    while (!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();

        for (int i = 0; i < 4; i++) {
            auto [t, ch] = check(grid, x, y, n, m, i);
            if (!t) continue;
            if (ch == '#') continue;
            parent[]= {x, y};
        }
    }

    for (int i = n;)
}