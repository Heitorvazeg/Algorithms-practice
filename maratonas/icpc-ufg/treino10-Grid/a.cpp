#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool check(vector<vector<long long>>& grid, int x, int y, int n, int it) {
    if (x+dx[it] < 0 || x+dx[it] >= n) {
        return false;

    } else if (y+dy[it] < 0 || y+dy[it] >= n) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<vector<long long>> grid(n, vector<long long>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> fila;

    fila.push({0, 0});
    visited[0][0] = true;

    while (!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();

        for (int i = 0; i < 8; i++) {
            if (!check(grid, x, y, n, i)) continue;
            if (visited[x+dx[i]][y+dy[i]]) continue;
            visited[x+dx[i]][y+dy[i]] = true;
            fila.push({x+dx[i], y+dy[i]});
            grid[x+dx[i]][y+dy[i]] = grid[x][y]+1;
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}