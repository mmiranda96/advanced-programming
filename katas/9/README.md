## Problem
You've built an inflight entertainment system with on-demand movie streaming. Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer `flight_length` (in minutes) and a list of integers `movie_lengths` (in minutes) and returns a boolean indicating whether there are two numbers in `movie_lengths` whose sum equals `flight_length`.

When building your function:
- Assume your users will watch exactly two movies
- Don't make your users watch the same movie twice
- Optimize for runtime over memory

## Naïve approach
```
for i -> 0 upto len - 1:
    for j -> i + 1 upto len - 1:
        if movie_lengths[i] + movie_lengths[j] = flight_length:
            return true

return false
```

This approach is O(n²) in runtime and O(1) in memory.

## Solution
```
// This hashtable allows duplicated keys
h := hashtable()

for i -> 0 upto len - 1:
    h[movie_lengths[i]] := i

for i -> 0 upto len - 1:
    delta := flight_length - movie_lengths[i]
    // This returns a list of all elements with given key
    complements := h[delta]
    // Check if there are more than one complements or that the complement is not itself
    if len(complements) > 1 || (len(complements = 1) && complements[0] != i):
        return true

return false
```

This approach is O(n) in runtime and O(n) in memory.
