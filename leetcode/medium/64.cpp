class Solution {
    // Naive Solution:
    // Concept: Test all possible paths, and see wich one has the minimum sum.
    // Can be done by recursion with backtracking.
    // O(2^n+m)

    // Optimized 1:
    // Concept: Think of the grid as a graph and do a djkistra to see the path
    // with minimum weight sum.
    // Not that opmital because it sees all the paths with min weigths that,
    // sometimes, cannot be the optimal path. It also sees the min path of
    // all the nodes, not just the one that we want to.
    // O(n*m log n*m)

    // Optimized 2:
    // Concept: Do a DP that stores the minimum value for reaching each position.
    // It can be done by seeing wich one is smaller, top or left, and add it to
    // the value of the position.
    // O(n*m) Just need to go trough one time.

public:
    bool validIndex(int i, int j, int m, int n) {
        if (i < 0 || i >= m) return false;
        else if (j < 0 || j >= n) return false;
        return true;
    }

    int minPathSum(vector<vector<int>>& grid) {
        // Set m and n, wich we use many times.
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        // DP vector with min values to reach each position.
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // Position (0, 0) = grid[0][0]
        dp[0][0] = grid[0][0];

        // Go through the matrix, and sum the min values.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // See if left and top is valid.
                bool validLeft = validIndex(i, j-1, m, n);
                bool validTop = validIndex(i-1, j, m, n);

                // See wich one is the minimum value between top and left or both.
                if (validLeft && validTop) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

                } else if (validLeft) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if (validTop) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
};