# Two Sum
Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have ***exactly*** one solution, and you may not use the same element twice.

## Example:
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

## Naïve approach.
```
/* 
 * Go through each element and add with each element that is forward
 * if it is less or equal to target
 */
for i := 0 -> numSize - 1:
    if nums[i] <= target:
        for j := i -> numSize - 1:
            if nums[i] + nums[j] == target:
                return [i, j]

```

## Solution no. 1:
```
/* 
 * Sort the array of numbers takes O(n)
 */
sortedNums := radixSort(nums)

/* 
 * Go through each element and search the aditive inverse
 * if it is less or equal to target
 */
for i := 0 -> numSize - 1:
    if nums[i] <= target:
        inv := target - nums[i]
        
        /*
         * Binary search searches takes O(lg n)
         * and returns -1 if element is not found
         */
        j := binarySearch(inv)
        if j > 0:
            return [i, j]

```

## Solution no. 2:
```
/*
 * Create a new hash table
 */
ht := newHashTable()

/*
 * Add each element to the hash table
 * if it is less or equal to target
 */
for i := 0 -> numSize - 1:
    if nums[i] <= target:
        ht.add(nums[i], i)

/*
 * Go through each element and search the aditive inverse
 * if it is less or equal to target
 */
for i := 0 -> numSize - 1:
    if nums[i] <= target:
        inv := target - nums[i]
        j := ht.get(inv)
        if j:
            return [i, j]
```