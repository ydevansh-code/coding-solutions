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