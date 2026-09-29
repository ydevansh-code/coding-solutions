# Sudoku Solver

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy  **all of the following rules** :

- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The `'.'` character indicates empty cells.

 

 **Example 1:** 

```
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

```

 

 **Constraints:** 

- board.length == 9
- board[i].length == 9
- board[i][j] is a digit or '.'.
- It is guaranteed that the input board has only one solution.

## Solution

**Language:** C  
**Runtime:** 323 ms (beats 82.53%)  
**Memory:** 9.6 MB (beats 22.56%)  
**Submitted:** 2026-09-29T21:25:56.163Z  

```c
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
```

---

[View on LeetCode](https://leetcode.com/problems/sudoku-solver/)