int maxAscendingSum(int* nums, int numsSize) {
    int habgye =  nums[0];  // Current sum
    int choego = nums[0];   // Maximum sum

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] < nums[i]) {
            habgye += nums[i];
        } else {
            habgye = nums[i];
        }
        if (habgye > choego) {
            choego = habgye;
        }
    }

    return choego;
}