#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define printDebug(...) do {                                \
    char *isDebug;                                          \
    isDebug = getenv("DEBUG");                              \
    if (isDebug != NULL && !strcasecmp(isDebug, "y")) {     \
        fprintf(stderr, __VA_ARGS__);                       \
    }                                                       \
} while(0)

int main() {
    char *filename = "input.txt";
    FILE *input;
    char *search = "mundo";
    char *replace = "MUNDOMUNDO";
    char word[255];
    long searchPos = 0;
    int character = 0;
    input = fopen(filename, "r");
    while (1) {
        fscanf(input, "%s", word);
        if (feof(input)) {
            break;
        }
        if (!strcmp(word, search)) {
            printDebug("Found %s\n", word);
            fseek(input, -1 * strlen(search), SEEK_CUR);
            searchPos = ftell(input);
            printDebug("searchPos = %d\n", searchPos);
            rewind(input);
            while(ftell(input) != searchPos) {
                character = fgetc(input);
                fputc(stdout, character);
            }
            break;
        }
    }

    return 0;
}