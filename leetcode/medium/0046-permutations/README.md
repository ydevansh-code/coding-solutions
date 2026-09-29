# Permutations

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array `nums` of distinct integers, return all the possible permutations. You can return the answer in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

```

 **Example 2:** 

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]

```

 **Example 3:** 

```
Input: nums = [1]
Output: [[1]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 6
- -10 <= nums[i] <= 10
- All the integers of nums are unique.

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12.5 MB (beats 10.62%)  
**Submitted:** 2026-09-29T21:31:28.529Z  

```c
#include <stdlib.h>

void backtrack(
    int* nums,
    int numsSize,
    int start,
    int** result,
    int* returnSize,
    int* returnColumnSizes
) {
    // One complete permutation is ready
    if (start == numsSize) {

        result[*returnSize] = malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = nums[i];
        }

        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;

        return;
    }

    // Try every number at the current position
    for (int i = start; i < numsSize; i++) {

        // Choose
        int temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;

        // Recurse
        backtrack(
            nums,
            numsSize,
            start + 1,
            result,
            returnSize,
            returnColumnSizes
        );

        // Undo the choice
        temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;
    }
}

int** permute(
    int* nums,
    int numsSize,
    int* returnSize,
    int** returnColumnSizes
) {
    *returnSize = 0;

    // Maximum permutations = n!
    int capacity = 720;   // 6! = 720

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    backtrack(
        nums,
        numsSize,
        0,
        result,
        returnSize,
        *returnColumnSizes
    );

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/permutations/)