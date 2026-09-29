# Valid Sudoku

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated  **according to the following rules** :

- Each row must contain the digits 1-9 without repetition.
- Each column must contain the digits 1-9 without repetition.
- Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

 **Note:** 

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

 

 **Example 1:** 

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

```

 **Example 2:** 

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

```

 

 **Constraints:** 

- board.length == 9
- board[i].length == 9
- board[i][j] is a digit 1-9 or '.'.

## Solution

**Language:** C  
**Runtime:** 0 ms  
**Memory:** 8.7 MB  
**Submitted:** 2026-09-29T21:24:57.656Z  

```c
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.')
                continue;

            int num = board[i][j] - '1';

            // Find which 3x3 box this cell belongs to
            int boxIndex = (i / 3) * 3 + (j / 3);

            // Check duplicate
            if (row[i][num] || col[j][num] || box[boxIndex][num])
                return false;

            // Mark number as seen
            row[i][num] = 1;
            col[j][num] = 1;
            box[boxIndex][num] = 1;
        }
    }

    return true;
}
```

---

[View on LeetCode](https://leetcode.com/problems/valid-sudoku/)