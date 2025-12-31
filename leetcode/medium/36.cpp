class Solution {
    // Naive Solution: For each number in the sudoku board, iterate through the
    // line and the column and the 3x3 square to see if the number alredy exists.
    // O (3 * 9 * 9^2), calling 81 = n: O(3*n^3)

    // Optimized 1: Use hash tables to see if theres duplicates in a column,
    // line or square. Takes a lot of memory.

    // Optimized 2: Instead of storing a hash table or a set, stores a bitmask
    // to see if there is duplicates. Just a int.
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Each number in the arrays act like a bitmask
        int maskRow[9] = {};
        int maskColumn[9] = {};
        int maskSquare[9] = {};

        // Iterate through the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                // Converts the number in the board to integer
                int number = board[i][j] - '0';
                // The number-th bit represent either it exists in the row, column or square.
                int bit = (1 << number);
                // A way of seeing the index of the square
                int indexSquare = ((i/3) * 3) + (j/3);

                // See if the bitmask already has the number
                if (maskRow[i] & bit) return false;
                if (maskColumn[j] & bit) return false;
                if (maskSquare[indexSquare] & bit) return false;
                
                // If the number isn't there, put it.
                maskRow[i] |= bit;
                maskColumn[j] |= bit;
                maskSquare[indexSquare] |= bit;
            }
        }

        return true;
    }
};