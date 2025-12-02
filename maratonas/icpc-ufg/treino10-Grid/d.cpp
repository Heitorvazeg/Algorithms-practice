#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
char snuke[5] = {'s', 'n', 'u', 'k', 'e'};

bool seeChar(vector<vector<char>>& grid, int xi, int yi, int it, int itS) {
    if (grid[xi+dx[it]][yi+dy[it]] == snuke[itS]) return true;
    return false;
}

vector<pair<int, int>> findSnuke(vector<vector<char>>& grid, int x, int y) {
    vector<pair<int, int>> v;
    queue<pair<int, int>> fila;
    int c = 1;
    
    while(!fila.empty()) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 's') {
                findSnuke();
            }
        }
    }
}