class Solution {
    // Solution:

    // With backtracking, generate all possibles permutations.
    // Use BitMask to see if there is the same number in the column, line or 3x3.
    // We check all possible number with BitWise, using the BitMasks
    // Time Complexity: O(N!)

public:
    // Arrays of BitMasks to control each line, column and square
    int lines[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int columns[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int squares[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool found = false;
    
    bool check(int num, int i, int j) {
        // Check each possible invalid position
        if ((lines[i] & (1 << num))) return false;
        if ((columns[j] & (1 << num))) return false;
        if ((squares[((i/3) * 3) + (j/3)] & (1 << num))) return false;

        return true;
    }

    void generatePermutations(vector<vector<char>>& currentBoard, int pos) {
        // Base Case
        if (pos == 81) {
            found = true;
            return;
        }

        // Sets the iterators
        int i = pos/9;
        int j = pos%9;

        // Do the code only with empty positions
        if (currentBoard[i][j] != '.') {
            generatePermutations(currentBoard, pos+1);
            return;
        }

        // Test each of the 9 possible number
        for (int l = 1; l <= 9; l++) {
            // Checks which number is valid in the position
            if (!check(l, i, j)) continue;

            int num = l;

            // Set the BitMasks
            lines[i] |= (1 << num);
            columns[j] |= (1 << num);
            squares[((i/3) * 3) + (j/3)] |= (1 << num);

            currentBoard[i][j] = num + '0';

            // Backtrack
            generatePermutations(currentBoard, pos+1);

            // If we already found the correct solution, end the recursion
            if (found) return;

            lines[i] ^= (1 << num);
            columns[j] ^= (1 << num);
            squares[((i/3) * 3) + (j/3)] ^= (1 << num);

            currentBoard[i][j] = '.';
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // Mount the BitMasks with the initial board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    // Casting char to int
                    int num = board[i][j] - '0';

                    lines[i] |= (1 << num);
                    columns[j] |= (1 << num);
                    squares[((i/3) * 3) + (j/3)] |= (1 << num);
                }
            }
        }

        generatePermutations(board, 0);
    }
};