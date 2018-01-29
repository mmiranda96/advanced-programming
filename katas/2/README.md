# Strong Password Checker
A password is considered strong if below conditions are all met:
- It has at least 6 characters and at most 20 characters.
- It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
- It must NOT contain three repeating characters in a row (*"...aaa..."* is weak, but *"...aa...a..."* is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the **MINIMUM** change required to make a strong password. If s is already strong, return 0. Insertion, deletion or replace of any one character are all considered as one change.

# Solution
```
changes := 0

/*
 * Start by checking the character length
 */
l := len(password)
if len(password) < 6:
    changes := changes + (6 - l)
if len(password) > 20:
    changes := changes + (l - 20)

/*
 * Keep track of repeating characters, lowercase and uppercase letter and digits
 */
hasLowercase := false
hasUppercase := false
hasDigit := false
lastChar := 0
lastCharRepetitions := 0
for i := 0 -> len(password):
    /*
     * Check if character is repeating,
     * add 1 to changes for each three times it appears
     */
    if password[i] = lastChar:
        lastCharRepetitions := lastCharRepetitions + 1
    else:
        if lastCharRepetitions => 3 & lastCharRepetitions <= 7:
            changes := changes + 1
        else if lastChar > 7:
            changes := 
        /*
         * Assign new character and restart count
         */
        lastChar := password[i]
        lastCharRepetitions := 1
    /*
     * Check if character is lowercase
     */
    if lastChar >= 'a' & lastChar <= 'z':
        hasLowercase := true
    else if lastChar >= 'A' & lastChar <= 'Z':
        hasUppercase := true
    else if lastChar >= '0'  & lastChar <= '9':
        hasDigit := true

if !hasLowercase:
    changes := changes + 1
if !hasUppercase:
    changes := changes + 1
if !hasDigit:
    changes := changes + 1

return changes
```
