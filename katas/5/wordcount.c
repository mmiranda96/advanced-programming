#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wordcount.h"
#include "hash.h"

int isAlphanumeric(char);
char lowercase(char);
char * append(char *, char);

// Hash functions
unsigned hash(void *, unsigned);
void * copyKey(void *);
void * copyValue(void *);
int compareKeys(void *, void *);

Hash wordcount(FILE *file) {
    int wordIndex = 0;
    char *word = "";
    Hash h;
    initHash(&h, 1000, hash, copyKey, copyValue, compareKeys);
    
    int charValidator = fgetc(file);
    char c;
    while (charValidator != EOF) {
        c = (char) charValidator;
        if (isAlphanumeric(c)) {
           word = append(word, lowercase(c));
        }
        else if (strlen(word) > 0) {
            int value;
            if (contains(&h, (void *) word)) {
                value = *((int *) get(&h, (void *) word)) + 1;
                set(&h, (void *) word, (void *) &value);
            }
            else {
                value = 1;
                insert(&h, (void *) word, (void *) &value);
            }
            word = "";
        }
        charValidator = fgetc(file);
    }
    return h;
}

int isAlphanumeric(char c) {
    return (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

char lowercase(char c) {
    if (c >= 65 && c <= 90) {
        return c + 32; 
    }
    else {
        return c;
    }
}

char * append(char *s, char c) {
    int len = strlen(s);
    char *newString = (char *) malloc(sizeof(char) * (len + 2));
    for (int i = 0; i < len; i++) {
        newString[i] = s[i];
    }
    newString[len] = c;
    newString[len + 1] = 0;
    return newString;
}

unsigned hash(void *key, unsigned size) {
    unsigned char *str = (char *) key;
    unsigned hash = 5381;
    int c;

    while (c = *str++)
    hash = ((hash << 5) + hash) + c;

    return hash % size;
}

void * copyKey(void *key) {
    char *keyStr = (char *) key;
    char *newKey = (char *) malloc(sizeof(char) * strlen(keyStr));
    strcpy(newKey, keyStr);
    return (void *)newKey;
}

void * copyValue(void *value) {
    int *keyInt = (int *) value;
    int *newKey = (int *) malloc(sizeof(int));
    *newKey = *keyInt;
    return (void *)newKey;
}

int compareKeys(void *this, void *that) {
    return !strcmp((char *) this, (char *) that);
}
