#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "wordcount.h"

/* Add function signatures here */

void displayHash(Hash *);

int main(int argc, char **argv) {
    FILE *file = fopen("words.txt", "r");
    Hash h = wordcount(file);
    displayHash(&h);
    return 0;
}

void displayHash(Hash *h) {
    char *key;
    int value;
    for(int i = 0; i < h->size; i++) {
        for (int j = 0; j < h->data[i].count; j++) {
            key = (char *) h->data[i].elements[j].key;
            value = *((int *) h->data[i].elements[j].value);
            printf("%s: %d\n", key, value);
        }
    }
}