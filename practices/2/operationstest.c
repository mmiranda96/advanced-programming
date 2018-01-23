#include <stdio.h>
#include "operations.h"

void printTestMsg(int, char *, char *);
int testAddition(void);
int testSubstraction(void);

int main()
{
    // Test add
    printTestMsg(testAddition(),
                 "addition passed",
                 "addition failed");
    // Test substract
    printTestMsg(testSubstraction(),
                 "substraction passed",
                 "substraction failed");

    return 0;
}

void printTestMsg(int condition, char *msgPassed, char *msgFailed)
{
    if (condition)
    {
        printf("%s\n", msgPassed);
    }
    else
    {
        printf("%s\n", msgFailed);
    }
}

int testAddition()
{
    int a = 5;
    int b = 7;
    int result = add(a, b);
    int expected = a + b;
    return result == expected;
}

int testSubstraction()
{
    int a = 5;
    int b = 7;
    int result = substract(a, b);
    int expected = a - b;
    return result == expected;
}

