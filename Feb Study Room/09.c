// You are given a 0-indexed integer array nums. 
// A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
// Return the total number of bad pairs in nums.

#include <stdio.h>
#include "uthash.h"

struct stored_I {
    int sbt;
    int count;
    UT_hash_handle hh;
};

long long countBadPairs(int* nums, int numsSize) {
    struct stored_I* head = NULL;
    struct stored_I* store;
    long long badPairs = 0;
    long long goodPairs = 0;

    for (int i = 0; i < numsSize; i++) {
        int sbt = nums[i] - i;

        HASH_FIND_INT(head, &sbt, store);
        if (store == NULL) {
            store = (struct stored_I*)malloc(sizeof(struct stored_I));
            store->sbt = sbt;
            store->count = 1;
            HASH_ADD_INT(head, sbt, store);
        } else {
            goodPairs += store->count;
            store->count++;
        }
    }

    badPairs = (long long)numsSize * (numsSize - 1) / 2 - goodPairs;

    struct stored_I *current, *tmp;
    HASH_ITER(hh, head, current, tmp) { HASH_DEL(head, current); free(current); }

    return badPairs;
}