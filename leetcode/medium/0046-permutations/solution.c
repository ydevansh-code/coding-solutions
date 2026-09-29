#include <stdlib.h>

void backtrack(
    int* nums,
    int numsSize,
    int start,
    int** result,
    int* returnSize,
    int* returnColumnSizes
) {
    // One complete permutation is ready
    if (start == numsSize) {

        result[*returnSize] = malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = nums[i];
        }

        returnColumnSizes[*returnSize] = numsSize;
        (*returnSize)++;

        return;
    }

    // Try every number at the current position
    for (int i = start; i < numsSize; i++) {

        // Choose
        int temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;

        // Recurse
        backtrack(
            nums,
            numsSize,
            start + 1,
            result,
            returnSize,
            returnColumnSizes
        );

        // Undo the choice
        temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;
    }
}

int** permute(
    int* nums,
    int numsSize,
    int* returnSize,
    int** returnColumnSizes
) {
    *returnSize = 0;

    // Maximum permutations = n!
    int capacity = 720;   // 6! = 720

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    backtrack(
        nums,
        numsSize,
        0,
        result,
        returnSize,
        *returnColumnSizes
    );

    return result;
}