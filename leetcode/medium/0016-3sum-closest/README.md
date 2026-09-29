# 3Sum Closest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n` and an integer `target`.

Find three integers at  **distinct indices**  in `nums` such that the sum is  **closest**  to `target`.

Return the sum of the three integers.

You may assume that each input would have  **exactly**  one solution.

 

 **Example 1:** 

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```

 **Example 2:** 

```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

```

 

 **Constraints:** 

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -104 <= target <= 104

## Solution

**Language:** C  
**Runtime:** 0 ms  
**Memory:** 8.4 MB  
**Submitted:** 2026-09-29T21:20:41.335Z  

```c
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(int), compare);

    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            // Check whether this sum is closer
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            // Exact answer
            if (sum == target) {
                return sum;
            }

            // Need a bigger sum
            if (sum < target) {
                left++;
            }
            // Need a smaller sum
            else {
                right--;
            }
        }
    }

    return closest;
}
```

---

[View on LeetCode](https://leetcode.com/problems/3sum-closest/)