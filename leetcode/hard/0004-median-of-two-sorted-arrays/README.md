# Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

 **Example 1:** 

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

```

 **Example 2:** 

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

 

 **Constraints:** 

- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.9 MB (beats 86.19%)  
**Submitted:** 2026-09-29T21:17:25.236Z  

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    // Make nums1 the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int left = 0;
    int right = nums1Size;

    int total = nums1Size + nums2Size;
    int half = (total + 1) / 2;

    while (left <= right) {

        // Partition nums1
        int partition1 = (left + right) / 2;

        // Partition nums2
        int partition2 = half - partition1;

        int left1  = (partition1 == 0) ? -2147483648 : nums1[partition1 - 1];
        int right1 = (partition1 == nums1Size) ? 2147483647 : nums1[partition1];

        int left2  = (partition2 == 0) ? -2147483648 : nums2[partition2 - 1];
        int right2 = (partition2 == nums2Size) ? 2147483647 : nums2[partition2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {

            // Odd total length
            if (total % 2 != 0) {
                return (double)(left1 > left2 ? left1 : left2);
            }

            // Even total length
            int maxLeft = (left1 > left2) ? left1 : left2;
            int minRight = (right1 < right2) ? right1 : right2;

            return ((double)maxLeft + minRight) / 2.0;
        }

        // We took too many elements from nums1
        else if (left1 > right2) {
            right = partition1 - 1;
        }

        // We took too few elements from nums1
        else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}
```

---

[View on LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)