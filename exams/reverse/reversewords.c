#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reversewords.h"

char * reverseWords(char * sentence) {
    // Count words
    int wordCount = 1;
    int len = strlen(sentence);
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            wordCount++;
        }
    }

    // Store words separately
    char **words = (char **)malloc(sizeof(char *) * wordCount);
    for (int i = 0; i < wordCount; i++) {
        words[i] = (char *) malloc(sizeof(char) * 10);
    }
    int currentWord = 0;
    int currentWordIndex = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            currentWord++;
            currentWordIndex = 0;
        }
        else {
            words[currentWord][currentWordIndex++] = sentence[i];
        }
    }

    // Concatenate words in reverse order
    char *result = (char *) malloc(sizeof(char) * len);
    for (int i = 0; i < wordCount; i++) {
        strcat(result, words[wordCount - i - 1]);
        strcat(result, " ");
    }
    result[len] = 0;

    return result;
}
