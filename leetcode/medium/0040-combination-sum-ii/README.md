# Combination Sum II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used  **once**  in the combination.

 **Note:**  The solution set must not contain duplicate combinations.

 

 **Example 1:** 

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

 **Example 2:** 

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```

 

 **Constraints:** 

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12 MB (beats 62.83%)  
**Submitted:** 2026-09-29T21:29:05.062Z  

```c
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

void backtrack(
    int *candidates,
    int candidatesSize,
    int target,
    int start,
    int *current,
    int currentSize,
    int **result,
    int *returnSize,
    int *returnColumnSizes
) {
    // Target reached
    if (target == 0) {

        result[*returnSize] = malloc(currentSize * sizeof(int));

        for (int i = 0; i < currentSize; i++) {
            result[*returnSize][i] = current[i];
        }

        returnColumnSizes[*returnSize] = currentSize;
        (*returnSize)++;

        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Skip duplicate values at the same recursion level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Since array is sorted
        if (candidates[i] > target)
            break;

        // Choose
        current[currentSize] = candidates[i];

        // i + 1 because each number can be used only once
        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i + 1,
            current,
            currentSize + 1,
            result,
            returnSize,
            returnColumnSizes
        );
    }
}

int** combinationSum2(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
) {
    // Sort first
    qsort(candidates, candidatesSize, sizeof(int), compare);

    *returnSize = 0;

    // Problem guarantees fewer than 150 combinations
    int capacity = 150;

    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    // Maximum possible combination length
    int *current = malloc((target + 1) * sizeof(int));

    backtrack(
        candidates,
        candidatesSize,
        target,
        0,
        current,
        0,
        result,
        returnSize,
        *returnColumnSizes
    );

    free(current);

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)