#include <stdlib.h>
#include "hashtable.h"

// Create a new hash table
struct hashTable *newHashTable(int size, int bSize)
{
    struct hashTable *ht = (struct hashTable*)malloc(sizeof(struct hashTable));
    ht->buckets = (struct pair ***)malloc(sizeof(struct pair ***) * size);
    ht->bSize = (int *)malloc(sizeof(int) * size);
    ht->bCapacity = (int *)malloc(sizeof(int) * size);
    ht->size = size;
    for (int i = 0; i < size; i++)
    {
        ht->buckets[i] = calloc(sizeof(struct pair *), bSize);
        ht->bSize[i] = bSize;
        ht->bCapacity[i] = bSize;
    }

    return ht;
}

// Very simple hash functions, may lead to collisions
int hash(struct hashTable *ht, int key)
{
    return key % ht->size;
}

// Resizes one bucket
void resize(struct hashTable *ht, int index, int newSize)
{
    // Create new bucket
    struct pair **newB = (struct pair **)calloc(sizeof(int), newSize);
    
    // Copy elements to new bucket
    int prevSize = ht->bSize[index];
    for (int i = 0; i < prevSize; i++)
        newB[i] = ht->buckets[index][i];

    // Replace old bucket for new
    ht->bCapacity[index] = newSize - prevSize;
    free(ht->buckets[index]);
    ht->buckets[index] = newB;
}

// Push a value into the hash table
void push(struct hashTable *ht, int key, int value)
{
    int index = hash(ht, key);

    // Resize bucket if needed
    if (ht->bCapacity[index] == 0)
        resize(ht, index, ht->bSize[index] * 2);

    // Find the corresponding stack or position in the end
    int i = 0;
    for (;
         i < ht->bSize[index] - ht->bCapacity[index] &&
         ht->buckets[index][i]->key != key;
         i++);

    // Create a new pair (key-stack) if needed
    if (!ht->buckets[index][i])
    {
        struct pair *newPair = (struct pair*)malloc(sizeof(struct pair));
        ht->buckets[index][i] = newPair;
        ht->buckets[index][i]->key = key;
        ht->buckets[index][i]->stack = NULL;
        ht->bCapacity[index]--;
    }

    // Push into the stack
    struct node *head = ht->buckets[index][i]->stack;
    struct node *new = malloc(sizeof(struct node*));
    new->value = value;
    new->next = head;
    ht->buckets[index][i]->stack = new;
}

// Pop an element from the hash table stack
int pop(struct hashTable *ht, int key)
{
    int index = hash(ht, key);

    // Find the corresponding stack
    int i;
    for (i = 0;
         i < ht->bSize[index] - ht->bCapacity[index] &&
         ht->buckets[index][i]->key != key;
         i++);

    // Retrieve head's value
    int result = ht->buckets[index][i]->stack->value;

    // Pop
    struct node *next = ht->buckets[index][i]->stack->next;
    free(ht->buckets[index][i]->stack);
    ht->buckets[index][i]->stack = next;

    return result;
}
