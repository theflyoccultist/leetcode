// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices 
// in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one 
// of the strings. Otherwise, return false.

#include <stdio.h>
#include <stdbool.h>

bool areAlmostEqual(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    };

    int mismatch = 0;
    int firstMismatch = -1, secondMismatch = -1;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            mismatch++;
            if (mismatch == 1) {
                firstMismatch = i;
            } else if (mismatch == 2) {
                secondMismatch = i;
            } else {
                return false;
            }
        }    
    }
    
    return mismatch == 0 || 
            (mismatch == 2 && s1[firstMismatch] == s2[secondMismatch] && s1[secondMismatch] == s2[firstMismatch]);
}