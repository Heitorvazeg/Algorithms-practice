#include <bits/stdc++.h>

int qtd = 0;

using namespace std;

int cnt(vector<vector<char>>& grid) {
    int c = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (grid[i][j] == '#') c++;
        }
    }
    return c;
}

bool check(vector<vector<char>>& grid, int i, int j) {
    for (int l = 0; l < 8; l++) {
        if (grid[i][l] == '#') {
            return false;
        }
    }

    for (int l = 0; l < 8; l++) {
        if (grid[l][j] == '#') {
            return false;
        }
    }

    for (int l = 0; l < 8; l++) {
        for (int k = 0; k < 8; k++) {
            if (abs(l - i) == abs(k - j)) {
                if (grid[l][k] == '#') return false;
            }
        }
    }

    return true;
}

void gen(vector<vector<char>>& grid, int i, int j) {
    if (j == 8) {
        i++;
        j = 0;
    }
    if (i == 8) {
        if (cnt(grid) == 8) {
            qtd++;
        }
        return;
    }
    gen(grid, i, j+1);
    if (grid[i][j] != '*' && check(grid, i, j)) {
        grid[i][j] = '#';
        gen(grid, i, j+1);
        grid[i][j] = '.';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<char>> grid(8, vector<char>(8, '.'));
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }

    gen(grid, 0 ,0);

    cout << qtd << "\n";
}