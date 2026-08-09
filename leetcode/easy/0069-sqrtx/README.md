# Sqrt(x)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a non-negative integer `x`, return  *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be  **non-negative**  as well.

You  **must not use**  any built-in exponent function or operator.

- For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

 **Example 1:** 

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

```

 **Example 2:** 

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

```

 

 **Constraints:** 

- 0 <= x <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.7 MB (beats 14.96%)  
**Submitted:** 2026-08-09T11:27:42.261Z  

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int start = 1, end = x, ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sqrtx/)