# Problem
You are given an integer N, followed by N lines of input (1 <= N <= 100). Each line of input contains one or several words separated with single spaces. Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. The total number of words in the input is between 1 and 100, inclusive.

Your task is to reverse the order of words in each line of input, while preserving the words themselves. The lines of your output should not have any trailing or leading spaces.

# Example

## Input
```
3
Hello World
Bye World
Useless World
```

## Output
```
World Hello
World Bye
World Useless
```

# Solution
Read each line as a whole string. For each case, do the following:
1. Count words (this can be done by counting spaces + 1).
2. Make an array of strings.
3. Scan the sentence and store each word on the array.
4. Traverse the array backwards and concatenate words.

# Complexity
O(n) in time, O(n) in memory.
