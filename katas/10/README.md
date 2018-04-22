# UTF-8 Validation
## Problem
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
1. For 1-byte character, the first bit is a 0, followed by its unicode code.
2. For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:
```
  Char number range  |        UTF-8 octet sequence
 --------------------+------------------------------------
 0000 0000-0000 007F | 0xxxxxxx
 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  

```
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

**Note:**
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

## Example 1
```
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
Return true
```
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.  

## Example 2
```
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
Return false
```
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character. The next byte is a continuation byte which starts with 10 and that's correct. But the second continuation byte does not start with 10, so it is invalid.

## Solution
Depending on the following ranges, verify the number of characters:
    1. `0b0000_0|000 - 0b0111_1|111 (0x00 - 0x7F)`: 0 follow-up characters required
    2. `0b1100_0|000 - 0b1101_1|111 (0xC0 - 0xDF)`: 1 follow-up characters required
    3. `0b1110_0|000 - 0b1110_1|111 (0xE0 - 0xEF)`: 2 follow-up characters required
    4. `0b1111_0|000 - 0b1111_0|111 (0xF0 - 0xF7)`: 3 follow-up characters required
if `n > 1`, verify that each additional character starts with `0b10xx_xxxx` with the mask `(c & 0xC0) == 0x80`.
Always keep track of required follow-up characters. If the array without all the required follow-up characters, return `false`.