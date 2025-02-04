/*
Given an integer array nums, move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.
*/

void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void moveZeroes(int* nums, int numsSize) {
    int left = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != 0) {
            if (nums[left] == 0) {
                swap(nums, left, right);
            }
            left++;
        }
    }
}