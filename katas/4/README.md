# Valid Number
Validate if a given string is numeric.

## Example:
```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
```

## Solution:
Use a finite automata. The automata will be the following:
```
Q = {q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, qx}
Σ = {d, "e", ".", ",", _}
S = q0
F = {q1, q6, q7, q9}
δ =
+---+---+---+---+---+---+
|   | d | e | . | , | _ |
+---+---+---+---+---+---+
| q0| q1| qx| q5| qx| q0|
+---+---+---+---+---+---+
| q1| q1| q8| q6| q2|q10|
+---+---+---+---+---+---+
| q2| q3| qx| qx| qx| qx|
+---+---+---+---+---+---+
| q3| q4| qx| qx| qx| qx|
+---+---+---+---+---+---+
| q4| q1| qx| qx| qx| qx|
+---+---+---+---+---+---+
| q5| q7| qx| qx| qx| qx|
+---+---+---+---+---+---+
| q6| q7| qx| qx| qx|q10|
+---+---+---+---+---+---+
| q7| q7| q8| qx| qx|q10|
+---+---+---+---+---+---+
| q8| q9| qx| qx| qx| qx|
+---+---+---+---+---+---+
| q9| q9| qx| qx| qx|q10|
+---+---+---+---+---+---+
|q10| qx| qx| qx| qx|q10|
+---+---+---+---+---+---+
| qx| qx| qx| qx| qx| qx|
+---+---+---+---+---+---+
```
In order for the automata to work, use an int to store the current state, an array of transitions and an array of final states. Iterate through the string and use the finite automata.

## Note:
```d``` is the equivalent of any digit and ```_``` is the equivalent of a space.

