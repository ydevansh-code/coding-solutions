#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(
    int *candidates,
    int candidatesSize,
    int target,
    int start,
    int *current,
    int currentSize,
    int **result,
    int *returnSize,
    int *returnColumnSizes
) {
    // Target reached
    if (target == 0) {

        result[*returnSize] = malloc(currentSize * sizeof(int));

        for (int i = 0; i < currentSize; i++) {
            result[*returnSize][i] = current[i];
        }

        returnColumnSizes[*returnSize] = currentSize;
        (*returnSize)++;

        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Since sorted, no later value can work
        if (candidates[i] > target)
            break;

        // Choose
        current[currentSize] = candidates[i];

        // Use the same candidate again
        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i,
            current,
            currentSize + 1,
            result,
            returnSize,
            returnColumnSizes
        );

        // Undo choice
        // Nothing needs to be erased because currentSize
        // is passed by value
    }
}

int** combinationSum(
    int* candidates,
    int candidatesSize,
    int target,
    int* returnSize,
    int** returnColumnSizes
) {
    qsort(candidates, candidatesSize, sizeof(int), compare);

    *returnSize = 0;

    // Problem guarantees fewer than 150 combinations
    int capacity = 150;

    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    // Maximum possible length is target
    int *current = malloc((target + 1) * sizeof(int));

    backtrack(
        candidates,
        candidatesSize,
        target,
        0,
        current,
        0,
        result,
        returnSize,
        *returnColumnSizes
    );

    free(current);

    return result;
}