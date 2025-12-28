class Solution {
    // Solution:
    // Concept: For each land we do a BFS to see horizontaly and verticaly in a
    // continuous way. If it is land, we add the position of the land to a vector
    // of booleans visited. We do this to all positions that are land and not
    // visited, ignoring the positions that are water. After that, the total of
    // island would be how many times we did BFS.
    // O(n*m) -> just what takes to go through the matrix
public:
    int xN[4] = {-1, 0, 0, 1};
    int yN[4] = {0, -1, 1, 0};

    bool validIndex(int i, int j, int m, int n) {
        if (i < 0 || i >= m) return false;
        if (j < 0 || j >= n) return false;
        return true;
    }

    void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        queue<tuple<int, int>> qu;
        qu.push({i, j});
        visited[i][j] = true;

        while (!qu.empty()) {
            auto [iTop, jTop] = qu.front();
            qu.pop();

            for (int l = 0; l < 4; l++) {
                if (!validIndex(iTop+xN[l], jTop+yN[l], m, n)) continue;
                if (visited[iTop+xN[l]][jTop+yN[l]]) continue;
                if (grid[iTop+xN[l]][jTop+yN[l]] == '0') continue;

                visited[iTop+xN[l]][jTop+yN[l]] = true;
                qu.push({iTop+xN[l], jTop+yN[l]});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // Sets m and n
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        int numberOfIslands = 0;

        // vector of visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Go through the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;

                BFS(grid, visited, i, j, m, n);
                numberOfIslands++;
            }
        }

        return numberOfIslands;
    }
};