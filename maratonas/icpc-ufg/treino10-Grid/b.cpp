#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

bool check(vector<vector<int>>& grid, int x, int y, int n, int it) {
    if (x+dx[it] < 0 || x+dx[it] >= n) {
        return false;

    } else if (y+dy[it] < 0 || y+dy[it] >= n) 
    {
        return false;
    }

    return true;
}

int bfs(vector<vector<int>> grid, pair<int, int> src, pair<int, int> dest) {
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<pair<int, int>> fila;
    fila.push(src);
    visited[src.first][src.second] = true;

    while (!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();

        if (x == dest.first && y == dest.second) {
            return grid[x][y]+1;
        }

        for (int i = 0; i < 8; i++) {
            int ddx = dx[i] + x;
            int ddy = dy[i] + y;
            if (!check(grid, x, y, 8, i)) continue;
            if (visited[ddx][ddy]) continue;

            visited[ddx][ddy] = true;
            fila.push({ddx, ddy});
            grid[ddx][ddy] = grid[x][y]+1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string sqr1, sqr2;
        cin >> sqr1 >> sqr2;

        vector<vector<int>> grid(8, vector<int>(8, 0));
        pair<int, int> p1;
        p1.first = sqr1[0] - 'a';
        p1.second = 8 - (sqr1[1] - '0');
        pair<int, int> p2;
        p2.first = sqr2[0] - 'a';
        p2.second = 8 - (sqr2[1] - '0');
        int depth = bfs(grid, p1, p2);

        cout << depth-1 << "\n";
    }
}