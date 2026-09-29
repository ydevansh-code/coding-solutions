# Combination Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of  **distinct**  integers `candidates` and a target integer `target`, return  *a list of all  **unique combinations**  of* `candidates` *where the chosen numbers sum to* `target` *.*  You may return the combinations in  **any order**.

The  **same**  number may be chosen from `candidates` an  **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

 **Example 1:** 

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

```

 **Example 2:** 

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

```

 **Example 3:** 

```
Input: candidates = [2], target = 1
Output: []

```

 

 **Constraints:** 

- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40
- All elements of candidates are distinct.
- 1 <= target <= 40

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.7 MB (beats 78.50%)  
**Submitted:** 2026-09-29T21:28:29.609Z  

```c
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
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

        // Since sorted, no later value can work
        if (candidates[i] > target)
            break;

        // Choose
        current[currentSize] = candidates[i];

        // Use the same candidate again
        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i,
            current,
            currentSize + 1,
            result,
            returnSize,
            returnColumnSizes
        );

        // Undo choice
        // Nothing needs to be erased because currentSize
        // is passed by value
    }
}

int** combinationSum(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    *returnSize = 0;

    // Problem guarantees fewer than 150 combinations
    int capacity = 150;

    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    // Maximum possible length is target
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

[View on LeetCode](https://leetcode.com/problems/combination-sum/)