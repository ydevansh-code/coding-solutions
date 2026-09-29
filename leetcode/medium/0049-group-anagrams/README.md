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
**Runtime:** 0 ms  
**Memory:** 8.8 MB  
**Submitted:** 2026-09-29T21:35:04.340Z  

```c
#include <stdlib.h>
#include <string.h>

void sortString(char *str) {
    int i, j;
    char temp;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    char*** result = malloc(strsSize * sizeof(char**));
    int* columns = malloc(strsSize * sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {

        // Make a sorted copy of the current string
        char key[101];
        strcpy(key, strs[i]);
        sortString(key);

        int found = -1;

        // Check whether this anagram group already exists
        for (int g = 0; g < groupCount; g++) {

            if (strcmp(result[g][0], key) == 0) {
                found = g;
                break;
            }
        }

        if (found == -1) {

            // Create a new group
            found = groupCount;

            result[found] = malloc(strsSize * sizeof(char*));

            // Store the first string
            result[found][0] = malloc(strlen(strs[i]) + 1);
            strcpy(result[found][0], strs[i]);

            columns[found] = 1;
            groupCount++;

        } else {

            // Add string to existing group
            int size = columns[found];

            result[found][size] = malloc(strlen(strs[i]) + 1);
            strcpy(result[found][size], strs[i]);

            columns[found]++;
        }
    }

    *returnSize = groupCount;
    *returnColumnSizes = columns;

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/group-anagrams/)