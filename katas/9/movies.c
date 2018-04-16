#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "movies.h"

typedef struct s {
    int size;
    int *elements;
} Set;

unsigned hash(void *, unsigned);
void * copyKey(void *);
void * copyValue(void *);
int compareKeys(void *, void *);

int checkMovies(int flightLength, int *movieLengths, int movieSize)
{
    Hash *h = (Hash *) malloc(sizeof(Hash));
    initHash(h, movieSize, hash, copyKey, copyValue, compareKeys);

    // Add all movies to the hash table
    for (int i = 0; i < movieSize; i++) {
        int key = movieLengths[i];
        Set *equalMovies = (Set *) get(h, (void *) &key);
        
        if (equalMovies == NULL) { // If no movies are registered, add a new set
            Set *value = (Set *) malloc(sizeof(Set));
            value->size = 1;
            value->elements = (int *) malloc(sizeof(int));
            value->elements[0] = i;
            insert(h, (void *) &key, (void *) value);
        }
        else { // If movies are registered, add it to the set
            equalMovies->size++;
            equalMovies-> elements = (int *) realloc(equalMovies->elements, sizeof(int) * equalMovies->size);
            equalMovies->elements[equalMovies->size - 1] = i;
            set(h, (void *) &key, (void *) equalMovies);
        }
    }

    for (int i = 0; i < movieSize; i++) {
        int delta = flightLength - movieLengths[i];
        Set *complements = (Set *) get(h, (void *) &delta);
        if (complements != NULL && (complements->size > 1 || complements->elements[0] != i)) {
            return 1;
        }
    }

    return 0;
}

unsigned hash(void *key, unsigned size)
{
    int x = *((int *)key);
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % size;
}

void * copyKey(void *key)
{
    int prevKey = *((int *) key);
    int *newKey = (int *) malloc(sizeof(int));
    *newKey = prevKey;

    return (void *) newKey;
}

void * copyValue(void *value)
{
    Set *prevValue = (Set *) value;
    Set *newValue = (Set *) malloc(sizeof(Set));
    newValue->size = prevValue->size;
    newValue->elements = (int *) malloc(sizeof(int) * newValue->size);
    for (int i = 0; i < newValue->size; i++) {
        newValue->elements[i] = prevValue->elements[i];
    }

    return (void *) newValue;
}

int compareKeys(void *a, void *b)
{
    int aInt = *((int *) a);
    int bInt = *((int *) b);

    return aInt - bInt;
}
