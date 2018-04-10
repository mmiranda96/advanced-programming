#include <stdio.h>
#include <string.h>
#include "database.h"

int main(int argc, char **argv) {
    char *dbName = "student.dat";
    Student myStudent;
    char *searchName = argv[1];

    FILE *data = fopen(dbName, "rb");
    while (1) {
        fread(&myStudent, sizeof(Student), 1, data);
        if (feof(data)) {
            break;
        }
        if (!strcmp(myStudent.firstName, searchName)) {
            printf("Student info:\n");
            printf("ID: %d\n", myStudent.Id);
            printf("First name: %s\n", myStudent.firstName);
            printf("Last name: %s\n", myStudent.lastName);
            printf("Semester: %s\n", myStudent.semester);
            break;
        }
    }

    return 0;
}