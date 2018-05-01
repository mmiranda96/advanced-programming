# Partitions
## Problem
You are given an array **A** with size **N**. For each **K** between 1 and **N** (inclusive), find out if it is possible to partition (split) the array **A** into **K** contiguous subarrays such that the sum of elements within each of these subarrays is the same. Each element of the original array should belong to exactly one subarray.

## Input
- The first line of the input contains a single integer **T** denoting the number of test cases. The description of **T** test cases follows.
- The first line of each test case contains a single integer **N**.
- The second line contains **N** space-separated integers **A1**, **A2**, ..., **AN**.

## Output
For each test case, print a single line containing **N** characters. For each **K** `(1 ≤ K ≤ N)`, the **K**-th of these characters should be '1' if it is possible to partition the array in the desired way or '0' if it is impossible.

## Constraints
```
1 ≤ T ≤ 1,000,000
1 ≤ N ≤ 1,000,000
1 ≤ sum of N over all test cases ≤ 1,000,000
1 ≤ Ai ≤ 10^9 for each valid i
```

## Example
### Input:
```
3
5
1 4 2 3 5
4
1 1 1 1
4
1 1 2 2
```

### Output:
```
10100
1101
1010
```

## Solution
```
// Calculate the sum of the array
sum := 0
for i -> 0 upto N - 1:
    sum := sum + A[i]

result := ""
// When k = 1, it's always possible to partition
for k -> 2 upto N:
    // If the sum is not divisible by k, then it's not possible to partition
    if N % k != 0:
        result := result + "0"
        continue
    
    /*
     * If the sum is divisible by k, iterate through each element of A adding A[i]
     * until the temporal sum is equal to N / k. If on one addition the temporal
     * sum suprassses N / k or i = N - 1 and the temporal sum is not N / k
     * or the number of partitions is not N / k, then it's not possible to partition.
     */
    temp := 0
    partitions = 1
    for i -> 0 upto N - 1:
        if temp > N / k:
            break

        if temp = N / k:
            partitions := partitions + 1
            temp := 0
        temp := temp + A[i]
    
    if temp != N / k || partitions != k:
        result := result + "0"
    else:
        result := result + "1"

return result
```
The complexity of this algorithm is O(n²) in time and O(1) in memory.