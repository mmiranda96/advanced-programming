# Anagram Mappings
Given two lists **A** and **B**, and **B** is an anagram of **A**. **B** is an anagram of **A** means **B** is made by randomizing the order of the elements in **A**.

We want to find an index mapping **P**, from **A** to **B**. **A** mapping **P[i] = j** means the ith element in **A** appears in **B** at index **j**.

These lists **A** and **B** may contain duplicates. If there are multiple answers, output any of them.

## Example:
For example, given
```
A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]  
```
We should return
```
[1, 4, 3, 2, 0]  
```
as **P[0] = 1** because the 0th element of **A** appears at **B[1]**, and **P[1] = 4** because the 1st element of **A** appears at **B[4]**, and so on.

## Note:
1. **A, B** have equal lengths in range **[1, 100]**.
2. **A[i], B[i]** are integers in range **[0, 10^5]**.

## Naïve approach:
```
/* 
 * Go through each element on A and find its position in B
 * by checking all elements in B.
 */
p := []
for i := 0 -> size:
    for j := 0 -> size:
        if b[j] == a[i]:
            p[i] = j
            break
return p
```

## Solution no. 1:
```
/*
 * Create a hash table which holds as key the value of a[i]
 * and as value a stack which holds the positions i of the key
 * (it can be multiple times).
 */ 
 ht := newHashTable()

/*
 * Traverse B and for each element add it to the hash table.
 * This takes n * O(1 + α).
 */
 for i := 0 -> size:
    ht[b[i]].push(i)

/*
 * Traverse A and for each element pop the corresonding element
 * in the hash table. This takes n * O(1 + α), giving a good
 * final complexity of O(n).
 */
p := []
for i := 0 -> size:
    j := ht[a[i]].pop(i)
    p[i] = j
return p
```