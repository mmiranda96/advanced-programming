#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tidy.h"

void remainTrailZeros(char *);

char * lastTidyNumber(char *n)
{
    int len = strlen(n);
    char *result = (char *) malloc(sizeof(char) * len);
    result[0] = n[0];
    for (int i = 1; i < len; i++) {
        if (n[i] < n[i - 1]) { // Chars can be compared safely
            int j = i - 1;
            while (result[j - 1] == n[i - 1] && j > 0) {
                j--;
            }
            result[j]--; // This is never zero, therefore it can never get out of numbers
            for (int k = j + 1; k < len; k++) {
                result[k] = '9';
            }
            remainTrailZeros(result);
            return result;
        }
        else {
            result[i] = n[i];
        }
    }

    return result;
}

void remainTrailZeros(char *n)
{
    if (n[0] != '0') { // No preceding zeros
        return;
    }

    int len = strlen(n);
    for (int i = 0; i < len - 1; i++) {
        n[i] = n[i + 1];
    }

    n[len - 1] = 0; // Set string terminator to prevent printing extra chars
}
