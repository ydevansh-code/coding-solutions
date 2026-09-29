#include <stdbool.h>

bool backtrack(char** board) {

    // Find an empty cell
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] == '.') {

                // Try numbers 1 to 9
                for (char num = '1'; num <= '9'; num++) {

                    bool valid = true;

                    // Check row
                    for (int j = 0; j < 9; j++) {
                        if (board[row][j] == num) {
                            valid = false;
                            break;
                        }
                    }

                    // Check column
                    if (valid) {
                        for (int i = 0; i < 9; i++) {
                            if (board[i][col] == num) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    // Check 3x3 box
                    if (valid) {
                        int startRow = (row / 3) * 3;
                        int startCol = (col / 3) * 3;

                        for (int i = startRow; i < startRow + 3; i++) {
                            for (int j = startCol; j < startCol + 3; j++) {

                                if (board[i][j] == num) {
                                    valid = false;
                                    break;
                                }
                            }

                            if (!valid)
                                break;
                        }
                    }

                    // If valid, place the number
                    if (valid) {
                        board[row][col] = num;

                        // Solve remaining cells
                        if (backtrack(board))
                            return true;

                        // Wrong choice, undo it
                        board[row][col] = '.';
                    }
                }

                // No number worked
                return false;
            }
        }
    }

    // No empty cells → Sudoku solved
    return true;
}


void solveSudoku(char** board, int boardSize, int* boardColSize) {
    backtrack(board);
}