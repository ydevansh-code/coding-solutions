int jump(int* nums, int numsSize) {

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++) {

        // Find the farthest position reachable
        farthest = (farthest > i + nums[i])
                  ? farthest
                  : i + nums[i];

        // We have reached the end of our current jump
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}