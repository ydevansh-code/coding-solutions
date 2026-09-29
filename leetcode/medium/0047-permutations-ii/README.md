# Permutations II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of numbers, `nums`, that might contain duplicates, return  *all possible unique permutations  **in any order**.* 

 

 **Example 1:** 

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

```

 **Example 2:** 

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 8
- -10 <= nums[i] <= 10

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 17 MB (beats 8.41%)  
**Submitted:** 2026-09-29T21:31:56.808Z  

```c
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(
    int* nums,
    int numsSize,
    int* current,
    bool* used,
    int level,
    int** result,
    int* returnSize,
    int* returnColumnSizes
) {
    // Complete permutation
    if (level == numsSize) {

        result[*returnSize] = malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }

        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;

        return;
    }

    for (int i = 0; i < numsSize; i++) {

        // Already used
        if (used[i])
            continue;

        // Skip duplicate at the same level
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        // Choose
        used[i] = true;
        current[level] = nums[i];

        // Recurse
        backtrack(
            nums,
            numsSize,
            current,
            used,
            level + 1,
            result,
            returnSize,
            returnColumnSizes
        );

        // Undo
        used[i] = false;
    }
}

int** permuteUnique(
    int* nums,
    int numsSize,
    int* returnSize,
    int** returnColumnSizes
) {
    // Sort first
    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    // Maximum possible permutations = 8! = 40320
    int capacity = 40320;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    int* current = malloc(numsSize * sizeof(int));
    bool* used = calloc(numsSize, sizeof(bool));

    backtrack(
        nums,
        numsSize,
        current,
        used,
        0,
        result,
        returnSize,
        *returnColumnSizes
    );

    free(current);
    free(used);

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/permutations-ii/)