#include <stdio.h>
#include <string.h>

int isCircle(char*);

int main()
{
    char s[100];
    scanf("%s", s);
    if (isCircle(s))
    {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    return 0;
}

int isCircle(char *s)
{   
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'R')
        {
            x++;
        }
        else if (s[i] == 'L')
        {
            x--;
        }
        else if (s[i] == 'U')
        {
            y++;
        }
        else if (s[i] == 'D')
        {
            y--;
        }
    }

    return x == 0 && y == 0;
}