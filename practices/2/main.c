#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "messages.h"

#define MAX_STRLEN 100
#define LANG "en"

typedef struct
{
    char *operationName;
    int(* operation) (int, int);
} operation;

int main()
{
    char operation[MAX_STRLEN];
    int op1, op2;
    char **messages;

    if (!strcmp(LANG, "en"))
    {
        messages = message_EN;
    }
    if (!strcmp(LANG, "es"))
    {
        messages = message_ES;
    }

    printf("%s\n", messages[0]);
    scanf("%s", operation);
    scanf("%d %d", &op1, &op2);

    if (!strcmp(operation, "add"))
    {
        printf("%s: %d\n", messages[2], add(op1, op2));
    }
    else if (!strcmp(operation, "substract"))
    {
        printf("%s: %d\n", messages[2], substract(op1, op2));
    }
    else
    {
        printf("%s\n", messages[1]);
    }
    
    return 0;
}
