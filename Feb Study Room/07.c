// You are given an integer limit and a 2D array queries of size n x 2.
// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. 
// For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, 
// you need to find the number of distinct colors among the balls.
// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
// Note that when answering a query, lack of a color will not be considered as a color.

#include <stdlib.h>
#include <stdio.h>
#include "uthash.h"

struct ball {
    int label;
    int color;
    UT_hash_handle hh;
};

struct color_count {
    int color;
    int count;
    UT_hash_handle hh;
};

void fail(void) { printf("Memory could not be allocated\n"); exit(EXIT_FAILURE); }

int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    struct ball* g = NULL;
    struct color_count* cnt = NULL;
    struct ball* g_entry;
    struct color_count* cnt_entry;

    // Result array
    int* results = (int*)malloc(queriesSize * sizeof(int));
    if (!results) fail();

    for (int i = 0; i < queriesSize; i++) {
        int ball = queries[i][0];
        int color = queries[i][1];

        HASH_FIND_INT(cnt, &color, cnt_entry);
        if (!cnt_entry) {
            cnt_entry = (struct color_count*)malloc(sizeof(struct color_count));
            if (!cnt_entry) fail();

            cnt_entry->color = color;
            cnt_entry->count = 1;
            HASH_ADD_INT(cnt, color, cnt_entry);
        } else {
            cnt_entry->count++;
        }

        HASH_FIND_INT(g, &ball, g_entry);
        if (g_entry) {
            int old_color = g_entry->color;
            HASH_FIND_INT(cnt, &old_color, cnt_entry);
            if (cnt_entry) {
                cnt_entry->count--;
                if (cnt_entry->count == 0) {
                    HASH_DEL(cnt, cnt_entry);
                    free(cnt_entry);
                }
            }
        } else {
            g_entry = (struct ball*)malloc(sizeof(struct ball));
            if (!g_entry) fail();
            g_entry->label = ball;
            HASH_ADD_INT(g, label, g_entry);
        }

        g_entry->color = color;

        int distinct_colors = HASH_COUNT(cnt);
        results[i] = distinct_colors;
    }

    struct ball* g_tmp;
    HASH_ITER(hh, g, g_entry, g_tmp) {
        HASH_DEL(g, g_entry);
        free(g_entry);
    }

    struct color_count* cnt_tmp;
    HASH_ITER(hh, cnt, cnt_entry, cnt_tmp) {
        HASH_DEL(cnt, cnt_entry);
        free(cnt_entry);
    }

    *returnSize = queriesSize;
    return results;
}
