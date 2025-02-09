#include <stdbool.h>

bool validPartition(int* nums, int numsSize) {
    if (numsSize < 2) return false;

    bool dp[numsSize];
    dp[0] = false;
    dp[1] = nums[0] == nums[1];

    if (numsSize > 2) {
        dp[2] = (nums[0] == nums[1] && nums[1] == nums[2]) ||
                (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]);
    }

    for (int i = 3; i < numsSize; i++) {
        dp[i] = false;
        
        if (nums[i] == nums[i - 1] && dp[i - 2]) {
            dp[i] = true;
        }
        // Check for triplet of same elements ending at i
        if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && dp[i - 3]) {
            dp[i] = true;
        }
        
        if (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2 && dp[i - 3]) {
            dp[i] = true;
        }
    }

    return dp[numsSize - 1];
}
