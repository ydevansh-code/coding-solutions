# First Missing Positive

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an unsorted integer array `nums`. Return the  *smallest positive integer*  that is  *not present*  in `nums`.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

 

 **Example 1:** 

```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

```

 **Example 2:** 

```
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

```

 **Example 3:** 

```
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -231 <= nums[i] <= 231 - 1

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.7 MB (beats 12.79%)  
**Submitted:** 2026-09-29T21:29:37.983Z  

```c
int firstMissingPositive(int* nums, int numsSize) {

    int i = 0;

    // Put each number at its correct position
    while (i < numsSize) {

        int correctIndex = nums[i] - 1;

        if (nums[i] > 0 &&
            nums[i] <= numsSize &&
            nums[i] != nums[correctIndex]) {

            // Swap nums[i] with nums[correctIndex]
            int temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;
        }
        else {
            i++;
        }
    }

    // Find the first number which is not in its correct place
    for (i = 0; i < numsSize; i++) {

        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If 1...numsSize are all present
    return numsSize + 1;
}
```

---

[View on LeetCode](https://leetcode.com/problems/first-missing-positive/)