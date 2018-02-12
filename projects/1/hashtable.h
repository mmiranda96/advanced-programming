#include "list.h"

typedef struct pair
{
    int key;
    List *value;
} Pair;

typedef struct bucketnode
{
    Pair *value;
    struct bucketnode *next;
} BucketNode;

typedef struct bucket
{
    int size;
    BucketNode *head;
} Bucket;

typedef struct hashtable
{
    // Array of list pointers
    Bucket **buckets;
    int bucketsNumber;
} HashTable;

HashTable* newHashTable(int);
void add(HashTable*, int, int);
List* get(HashTable*, int);
