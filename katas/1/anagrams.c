#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int* anagrams(int *a, int *b, int size)
{
    // Create a new hash table
    struct hashTable* ht = newHashTable(size, 5);

    // Store B's elements' position into the hash table
    for (int i = 0; i < size; i++)
        push(ht, b[i], i);

    // Create result array
    int *p = malloc(sizeof(int) * size);

    // Traverse A and find each element's position in B
    int j;
    for (int i = 0; i < size; i++)
        p[i] = pop(ht, a[i]);

    return p;
}

#define SIZE 5
int main()
{
    int a[SIZE] = {12, 28, 46, 32, 50};
    int b[SIZE] = {50, 12, 32, 46, 28};
    int *p = anagrams(a, b, SIZE);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", p[i]);
    printf("\n");
}
