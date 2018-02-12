#include <stdlib.h>
#include "hashtable.h"

Bucket* newBucket()
{
    Bucket *b = (Bucket*)malloc(sizeof(Bucket*));
    b->size = 0;
    b->head = NULL;

    return b;
}

void pushToBucket(Bucket* b, Pair *value)
{
    BucketNode *newHead = (BucketNode*)malloc(sizeof(BucketNode*));
    newHead->value = value;
    newHead->next = b->head;
    b->head = newHead;
    b->size++;
}

HashTable* newHashTable(int bucketsNumber)
{
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable*));
    
    ht->bucketsNumber = bucketsNumber;
    ht->buckets = (Bucket**)malloc(sizeof(Bucket*) * bucketsNumber);
    for (int i = 0; i < bucketsNumber; i++)
    {
        ht->buckets[i] = newBucket();
    }

    return ht;
}

int hash(HashTable *ht, int k)
{
    return k % ht->bucketsNumber;
}

List* get(HashTable* ht, int k)
{
    int keyHash = hash(ht, k);
    Bucket *bucket = ht->buckets[keyHash];
    for (BucketNode *it = bucket->head; it != NULL; it = it->next)
    {
        Pair *pair = it->value;
        if (pair->key == k)
        {
            return pair->value;
        }
    }

    return NULL;
}

void add(HashTable* ht, int k, int v)
{
    int keyHash = hash(ht, k);
    Bucket *bucket = ht->buckets[keyHash];
    for (BucketNode *it = bucket->head; it != NULL; it = it->next)
    {
        Pair *pair = it->value;
        if (pair->key == k)
        {
            // If key exists, push value to the lists
            push(pair->value, v);
            return;
        }
    }

    // If key is new, add new pair to bucket
    Pair *pair = malloc(sizeof(Pair*));
    pair->key = k;
    pair->value = newList();
    push(pair->value, v);
    pushToBucket(bucket, pair);
}