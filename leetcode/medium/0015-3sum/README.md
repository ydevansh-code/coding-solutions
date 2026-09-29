# 3Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

 

 **Example 1:** 

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

```

 **Example 2:** 

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

```

 **Example 3:** 

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

```

 

 **Constraints:** 

- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Solution

**Language:** C  
**Runtime:** 39 ms (beats 76.62%)  
**Memory:** 36.5 MB (beats 87.08%)  
**Submitted:** 2026-09-29T21:20:14.750Z  

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

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    int capacity = 10;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        // Skip duplicate nums[i]
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Since array is sorted
        if (nums[i] > 0)
            break;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                // Increase memory if needed
                if (*returnSize == capacity) {
                    capacity *= 2;

                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes =
                        realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Move both pointers
                left++;
                right--;

                // Skip duplicate left values
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicate right values
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/3sum/)