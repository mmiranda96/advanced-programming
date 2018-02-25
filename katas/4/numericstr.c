#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "numericstr.h"

#define T 1
#define F 0
#define N -1

int isDigit(char);
int mapChar(char);

int isNumeric(char *str)
{
    // {digit, e, dot, comma}
    int states[11][5] =
    {
        {1, N, 5, N,  0}, // 0
        {1, 8, 6, 2, 10}, // 1
        {3, N, N, N,  N}, // 2
        {4, N, N, N,  N}, // 3
        {1, N, N, N,  N}, // 4
        {7, N, N, N,  N}, // 5
        {7, N, N, N, 10}, // 6
        {7, 8, N, N, 10}, // 7
        {9, N, N, N,  N}, // 8
        {9, N, N, N, 10}, // 9
        {N, N, N, N, 10}, // 10
    };
    int finalStates[11] = {F, T, F, F, F, F, T, T, F, T, T};

    int currentState = 0;
    int len = strlen(str);
    char x;
    for (int i = 0; i < len; i++)
    {
        x = mapChar(str[i]);
        if (x < 0)
        {
            return F;
        }
        else
        {
            currentState = states[currentState][x];
        }

        if (currentState < 0)
        {
            return F;
        }
    }

    return finalStates[currentState];
}

int isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int mapChar(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 0;
    }
    else if (c == 'e')
    {
        return 1;
    }
    else if (c == '.')
    {
        return 2;
    }
    else if (c == ',')
    {
        return 3;
    }
    else if (c == ' ')
    {
        return 4;
    }
    else
    {
        return -1;
    }
} 