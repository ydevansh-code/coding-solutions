# Group Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of strings `strs`, group the anagrams together. You can return the answer in  **any order**.

 

 **Example 1:** 

 **Input:**  strs = ["eat","tea","tan","ate","nat","bat"]

 **Output:**  [["bat"],["nat","tan"],["ate","eat","tea"]]

 **Explanation:** 

- There is no string in strs that can be rearranged to form "bat".
- The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
- The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

 **Example 2:** 

 **Input:**  strs = [""]

 **Output:**  [[""]]

 **Example 3:** 

 **Input:**  strs = ["a"]

 **Output:**  [["a"]]

 

 **Constraints:** 

- 1 <= strs.length <= 104
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

## Solution

**Language:** C  
**Runtime:** 580 ms (beats 37.50%)  
**Memory:** 250.9 MB (beats 13.00%)  
**Submitted:** 2026-09-29T21:37:12.937Z  

```c
#include <stdlib.h>
#include <string.h>

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    char*** result = malloc(strsSize * sizeof(char**));
    int* columnSizes = malloc(strsSize * sizeof(int));

    // Store frequency of 26 letters for every group
    int (*keys)[26] = malloc(strsSize * sizeof(*keys));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {

        int count[26] = {0};

        // Count letters
        for (int j = 0; strs[i][j] != '\0'; j++) {
            count[strs[i][j] - 'a']++;
        }

        int found = -1;

        // Check whether this frequency pattern already exists
        for (int g = 0; g < groupCount; g++) {

            int same = 1;

            for (int k = 0; k < 26; k++) {
                if (keys[g][k] != count[k]) {
                    same = 0;
                    break;
                }
            }

            if (same) {
                found = g;
                break;
            }
        }

        // Create new group
        if (found == -1) {

            found = groupCount;

            for (int k = 0; k < 26; k++) {
                keys[found][k] = count[k];
            }

            result[found] = malloc(strsSize * sizeof(char*));

            result[found][0] = malloc(strlen(strs[i]) + 1);
            strcpy(result[found][0], strs[i]);

            columnSizes[found] = 1;

            groupCount++;
        }

        // Add to existing group
        else {

            int pos = columnSizes[found];

            result[found][pos] = malloc(strlen(strs[i]) + 1);
            strcpy(result[found][pos], strs[i]);

            columnSizes[found]++;
        }
    }

    free(keys);

    *returnSize = groupCount;
    *returnColumnSizes = columnSizes;

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/group-anagrams/)