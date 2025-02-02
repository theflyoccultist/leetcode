// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

//     '?' Matches any single character.
//     '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool helper(char *s, char *p, int i, int j, int **dp) {
    if (dp[i][j] != -1) return dp[i][j];

    if (p[j] == '\0') return dp[i][j] = (s[i] == '\0');

    if (p[j] == '*') {
        return dp[i][j] = helper(s, p, i, j + 1, dp) || (s[i] != '\0' && helper(s, p, i + 1, j, dp));
    }

    if (s[i] != '\0' && (p[j] == '?' || s[i] == p[j])) {
        return dp[i][j] = helper(s, p, i + 1, j + 1, dp);
    }

    return dp[i][j] = 0;
}

bool isMatch(char* s, char* p) {
    int n = strlen(s), m = strlen(p);

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        memset(dp[i], -1, (m + 1) * sizeof(int));
    }
    bool result = helper(s, p, 0, 0, dp);

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}