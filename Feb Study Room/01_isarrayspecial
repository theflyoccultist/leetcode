#include <stdio.h>
#include <stdbool.h>

bool isArraySpecial(int* nums, int numsSize) {
    int susja = numsSize - 1;
    for (int i = 0; i < susja; i++) {
        if ((nums[i] + nums[i + 1]) % 2 == 0) {
            return false;
        }
    }
    return true;
}