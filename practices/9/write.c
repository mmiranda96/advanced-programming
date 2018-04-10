#include <stdio.h>
#include "database.h"

int main()
{
    char *dbName = "student.dat";
    Student pAvanzada[10];

    for (int i = 0; i < 10; i++) {
        sprintf(pAvanzada[i].firstName, "name%d", i);
        sprintf(pAvanzada[i].lastName, "lastname%d", i);
        pAvanzada[i].Id = i;
        sprintf(pAvanzada[i].semester, "S%d", 6);
    }

    FILE *data = fopen(dbName, "wb");
    fwrite(pAvanzada, sizeof(Student), 10, data);
    fclose(data);

    return 0;
}