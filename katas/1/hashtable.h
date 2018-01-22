// Stack node
struct node
{
    int value;              // Value
    struct node *next;      // Following node
};

// Hash table
struct pair
{
    int key;                // Hashed key
    struct node *stack;     // Stack
};

// This hash table is a very simple design, not to be used in other problems
struct hashTable
{
    struct pair ***buckets; // Buckets
    int *bSize;             // Size of bucket
    int *bCapacity;         // Available free slots in bucket
    int size;               // Number of buckets
};

// Create a new hash table
struct hashTable* newHashTable(int size, int bSize);

// Push a value into the hash table
void push(struct hashTable *ht, int key, int value);

// Pop an element from the hash table stack
int pop(struct hashTable *ht, int key);
