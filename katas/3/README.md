# Judge Route Circle
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

## Example 1:
```
Input: "UD"
Output: true  
```
Example 2:
```
Input: "LL"
Output: false  
```

# Solution
```
/*
 * Have a counter for X and Y.
 */
x := 0
y := 0

/*
 * Iterate the string and for each character move as required.
 */
for i := 0 -> len(s):
    case s[i]:
    'R':
        x := x + 1
    'L':
        x := x - 1
    'U':
        y := y + 1
    'D':
        y := y - 1
    default:
        /*
         * Ignore or halt.
         */
    
return x = 0 && y = 0
```
