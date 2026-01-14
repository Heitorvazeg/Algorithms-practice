class Solution {
    // Solution:

    // With backtracking, we generate all possible permutation positions.
    // While we generate, we see if the queen can be in that square by seeing
    // the columns, lines and diagonals. If theres no valid position, we place
    // a char '.'.
    // Time: O(N * N!) or O(9 * 9!).

    // Optmized 1:

    // What if we dont have to iterate to all lines, columns and diagonals?
    // By optmizing the Check() query, that sees if a valid queen can be in
    // that square, we can make the algorithm runs in O(N!).
    // With BitMasks, we have a more optimized aprouch to see if it is a 
    // valid position.
    // O(N!)

    public:
    vector<vector<string>> permutations;

    // We never put two queens in the same line
    // that's the reasen why we dont have a line mask
    int colu = 0, diag1 = 0, diag2 = 0;

    bool check(int cMask, int d1Mask, int d2Mask) {
        if ((colu & cMask) || (diag1 & d1Mask) || (diag2 & d2Mask)) return false;
        return true;
    }

    // Recursive function to generate permutations
    void generatePermutations(int n, int row, vector<string>& currentPosition) {
        // Base case
        if ((int)currentPosition.size() == n) {
            permutations.push_back(currentPosition);
            return;
        }

        // Iterate through columns putting queens in valid positions
        for (int i = 0; i < n; i++) {
            // Bit of the positions
            int cMask = (1 << i);
            int d1Mask = (1 << (row - i + n - 1));
            int d2Mask = (1 << (row + i));

            if (!check(cMask, d1Mask, d2Mask)) continue;
            
            // If the 'i' column of the line is set as a queen, the rest will be '.'.
            string line(n, '.');
            line[i] = 'Q';

            currentPosition.push_back(line);

            // Set the queen in the bitMasks
            colu |= cMask;
            diag1 |= d1Mask;
            diag2 |= d2Mask;
            
            // Backtrack
            generatePermutations(n, row + 1, currentPosition);

            currentPosition.pop_back();

            colu ^= cMask;
            diag1 ^= d1Mask;
            diag2 ^= d2Mask;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> currentPosition;
        
        generatePermutations(n, 0, currentPosition);

        return permutations;
    }
};