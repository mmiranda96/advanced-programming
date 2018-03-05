# Infographic
## Description
You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table, where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

> "After beating the eggs, Dana read the next step:"  
> "Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 2.

## Solution
We assume that the worrds will come from a file. So, we need to read the file.
```
ht := newHash()
word := ""
while input:
    if currentChar is alphanumeric:
        word := word + lowercase(currentChar)
    else if len(word) > 0: // We don't want empty words
        if ht.contains(word):
            ht[word] := ht[word] + 1
        else:
            ht[word] := 1
        word := ""

for key, value in ht:
    print(key + ": " + value)
```
