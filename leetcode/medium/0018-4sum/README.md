# 4Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array `nums` of `n` integers, return  *an array of all the  **unique**  quadruplets*  `[nums[a], nums[b], nums[c], nums[d]]` such that:

- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in  **any order**.

 

 **Example 1:** 

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

```

 **Example 2:** 

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

```

 

 **Constraints:** 

- 1 <= nums.length <= 200
- -109 <= nums[i] <= 109
- -109 <= target <= 109

## Solution

**Language:** C  
**Runtime:** 0 ms  
**Memory:** 8.7 MB  
**Submitted:** 2026-09-29T21:21:35.514Z  

```c
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target,
             int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    int capacity = 16;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {

        // Skip duplicate first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            // Skip duplicate second element
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum = (long long)nums[i]
                              + nums[j]
                              + nums[left]
                              + nums[right];

                if (sum == target) {

                    // Increase result capacity if necessary
                    if (*returnSize == capacity) {
                        capacity *= 2;

                        result = realloc(
                            result,
                            capacity * sizeof(int*)
                        );

                        *returnColumnSizes = realloc(
                            *returnColumnSizes,
                            capacity * sizeof(int)
                        );
                    }

                    result[*returnSize] = malloc(4 * sizeof(int));

                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Move both pointers
                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if (sum < target) {
                    left++;
                }

                else {
                    right--;
                }
            }
        }
    }

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/4sum/)