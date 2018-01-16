#include <stdio.h>
#include <stdlib.h>

// Hash table
struct pair {
    int key;
    int value;
};

// This hash table is a very simple design, not to be used in other problems
struct hashTable {
    struct pair **buckets;
    int *bCapacity;
    int *bSize;
    int capacity;
};

// Initialize the hash table to a capacity and initial bucket size
void init(struct hashTable* ht, int capacity, int bSize) {
    ht->buckets = (struct pair **) malloc(sizeof(struct pair *) * capacity);
    ht->bSize = (int *) malloc(sizeof(int) * capacity);
    ht->bCapacity = (int *) malloc(sizeof(int) * capacity);
    ht->capacity = capacity;

    for (int i = 0; i < capacity; i++) {
        ht->buckets[i] = malloc(sizeof(struct pair) * bSize);
        ht->bCapacity[i] = bSize;
        ht->bSize[i] = bSize;
    }
}

// Very simple hash functions, may lead to collisions
int hash(struct hashTable *ht, int key) {
    return key % ht->capacity;
}

void resizeBucket(struct hashTable *ht, int index, int newSize) {
    // Copy elements
    struct pair *temp = (struct pair *)malloc(sizeof(int) * ht->bSize[index]);
    for (int i = 0; i < ht->bSize[index]; i++)
        temp[i] = ht->buckets[index][i];

    // Replace old bucket for new
    ht->bSize[index] = newSize;
    ht->bCapacity[index] = newSize;
    free(ht->buckets[index]);
    ht->buckets[index] = temp;
}

// Add a new key-value pair to the hash table
void add(struct hashTable *ht, int key, int value) {
    int keyHash = hash(ht, key);

    // Resize bucket if needed
    if (!ht->bCapacity) {
        int newSize = ht->bSize[keyHash] * 2;
        resizeBucket(ht, keyHash, newSize);
    }

    // Add to following place
    int bIndex = ht->bSize[keyHash] - ht->bCapacity[keyHash];
    ht->buckets[keyHash][bIndex].key = key;
    ht->buckets[keyHash][bIndex].value = value;
    ht->bCapacity[keyHash]--;
}

// Returns the value corresponding to the key or -1 if key does not exist
int get(struct hashTable *ht, int key) {
    int keyHash = hash(ht, key);

    struct pair p;
    for (int i = 0; i < ht->bSize[keyHash] - ht->bCapacity[keyHash]; i++) {
        p = ht->buckets[keyHash][i];
        if (p.key == key)
            return p.value;
    }
    return -1;
}

// Actual function
int* twoSum(int *nums, int numSize, int target) {
    struct hashTable ht;
    init(&ht, numSize, 5);

    for (int i = 0; i < numSize; i++) {
        if (nums[i] <= target)
            add(&ht, nums[i], i);
    }

    for (int i = 0; i < numSize; i++) {
        if (nums[i] <= target) {
            int inv = target - nums[i];
            if (inv == nums[i])
                continue;
            int j = get(&ht, inv);
            if (j >= 0) {
                int *result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numSize = 4;
    int target = 9;

    int *result = twoSum(nums, numSize, target);
    printf("[%d, %d]\n", result[0], result[1]);
}
