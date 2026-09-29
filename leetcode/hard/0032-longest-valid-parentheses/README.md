# Longest Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string containing just the characters `'('` and `')'`, return  *the length of the longest valid (well-formed) parentheses **substring*.

 

 **Example 1:** 

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

 **Example 2:** 

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

 **Example 3:** 

```
Input: s = ""
Output: 0

```

 

 **Constraints:** 

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Solution

**Language:** C  
**Runtime:** 3 ms  
**Memory:** 8.8 MB  
**Submitted:** 2026-09-29T21:23:02.463Z  

```c
int longestValidParentheses(char* s) {

    int stack[30005];
    int top = -1;

    // Starting boundary
    stack[++top] = -1;

    int maxLen = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '(') {
            // Store index of '('
            stack[++top] = i;
        }
        else {
            // Remove matching '('
            top--;

            if (top == -1) {
                // No valid starting point
                stack[++top] = i;
            }
            else {
                // Length of valid substring
                int len = i - stack[top];

                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}
```

---

[View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)