## Problem
Tatiana likes to keep things tidy. Her toys are sorted from smallest to largest, her pencils are sorted from shortest to longest and her computers from oldest to newest. One day, when practicing her counting skills, she noticed that some integers, when written in base 10 with no leading zeroes, have their digits sorted in non-decreasing order. Some examples of this are 8, 123, 555, and 224488. She decided to call these numbers tidy. Numbers that do not have this property, like 20, 321, 495 and 999990, are not tidy.

She just finished counting all positive integers in ascending order from 1 to **N**. What was the last tidy number she counted?

## Input
The first line of the input gives the number of test cases, **T**. **T** lines follow. Each line describes a test case with a single integer N, the last number counted by Tatiana.

## Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the last tidy number counted by Tatiana.

## Limits
1 ≤ T ≤ 100.
1 ≤ N ≤ 10^18.

## Sample
### Input 
```
4
132
1000
7
111111111111111110
```
 	
### Output
```
Case #1: 129
Case #2: 999
Case #3: 7
Case #4: 99999999999999999
```

## Naïve approach
Set `y` to 1. Count each number from 1 to **N** and, if 'ts a tidy number, replace `y` with it. Return `y`.

This approach works with small inputs, but it requires a full count. Counting to 10^18 is not effcient.

## Solution
Treat each number as a string. Do the following:
1. While each digit `i` is greater or equal than digit `i - 1`, register it for the result.
2. If digit `i` is smaller than digit `i - 1` previous, track all previous digits equal to digit `i - 1` (including this one).
3. Find the first digit equal to digit `i - 1`. Decrease it.
4. Fill remaining (`[i, j]`) digits with 9.
5. Remove all trailing zeros.

If each digit `i - 1` is smaller than `i`, then the last tidy number is **N**.
```
result := [len(N)]
result[0] := N[0]

for i -> 1 to len(N) - 1:
    if N[i] < N[i - 1]:
        j := i
        while result[j] == N[i - 1] and j > 0: // Find the first ocurrence of the digit
            j--
        for k -> j + 1 to len(N) - 1:
            result[k] := 9 // Fill the remaining digits with 9's
        return removeTrailZeros(result)
    else:
        result[i] := N[i]
return result // N is tidy
```
