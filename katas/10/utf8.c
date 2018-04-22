#include <stdlib.h>
#include <stdio.h>
#include "utf8.h"

int isValid(unsigned char *code, int len)
{
    int followingChars = 0;
    for (int i = 0; i < len; i++) {
        if (followingChars > 0) {
            if ((code[i] & 0xC0) != 0x80) {
                return 0;
            }
            followingChars--;
        }
        else {
            switch (code[i])
            {
                case 0x00 ... 0x7F: // 0000_0|000 - 0111_1|111
                    followingChars = 0;
                    break;
                case 0xC0 ... 0xDF: // 1100_0|000 - 1101_1|111
                    followingChars = 1;
                    break;
                case 0xE0 ... 0xEF: // 1110_0|000 - 1110_1|111
                    followingChars = 2;
                    break;
                case 0xF0 ... 0xF7: // 1111_0|000 - 1111_0|111
                    followingChars = 3;
                    break;
                default:
                    return 0;
            }
        }
    }

    return !followingChars;
}
