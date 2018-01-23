#include <assert.h>
#include "operations.h"

#define MIN_INT -2147483648
#define MAX_INT 2147483647

/**
 * Use long addition to catch overflow.
 */
int add(int a, int b)
{
    // Do the addition and check if there is an overflow
    long c = (long)a + b;
    assert(c >= MIN_INT && c <= MAX_INT);
    return (int)c;
}

/**
 * Use long substraction to catch overflow.
 */
int substract(int a, int b)
{
    // Do the substraction and check if there is an overflow
    long c = (long)a - b;
    assert(c >= MIN_INT && c <= MAX_INT);
    return (int)c;
}