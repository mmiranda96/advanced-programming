#include <stdio.h>
#include <string.h>
#include "database.h"

int main(int argc, char **argv) {
    char *dbName = "student.dat";
    Student myStudent;
    char *searchName = argv[1];
    char *newFirstName = argv[2];

    FILE *data = fopen(dbName, "r+b");
    while (1) {
        fread(&myStudent, sizeof(Student), 1, data);
        if (feof(data)) {
            break;
        }
        if (!strcmp(myStudent.firstName, searchName)) {
            strcpy(myStudent.firstName, newFirstName);
            fseek(data, -1 * sizeof(Student), SEEK_CUR);
            fwrite(&myStudent, sizeof(Student), 1, data);
            break;
        }
    }

    return 0;
}