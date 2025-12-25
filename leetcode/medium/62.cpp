// DP em grid.

class Solution {
public:
    bool validIndex(int i, int j, int n, int m) {
        if (i >= n || i < 0) return false;
        if (j >= m || j < 0) return false;
        return true;
    }

    int uniquePaths(int m, int n) {
        vector<vector<long long>> matrix(n, vector<long long>(m, 0));
        matrix[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                bool isUpperValid = validIndex(i, j-1, n, m);
                bool isLeftValid = validIndex(i-1, j, n, m);

                long long sum = 0;
                if (isUpperValid) sum += matrix[i][j-1];
                if (isLeftValid) sum += matrix[i-1][j];
                
                matrix[i][j] = sum;
            }
        }

        return matrix[n-1][m-1];
    }
};