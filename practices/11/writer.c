#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"

int main() {
    char *fileName = "student.dat";
    int fd = open(fileName, O_RDWR);
    Student *pAvanzada = (Student *) mmap(
        NULL,
        10 * sizeof(Student),
        PROT_READ | PROT_WRITE,
        MAP_FILE | MAP_SHARED,
        fd,
        0);
    close(fd);

    int id;
    printf("Give me ID: \n");
    scanf("%d", &id);
    printf("student[%d].firstName = %s\n", id, pAvanzada[id].firstName);

    munmap(pAvanzada, 10 * sizeof(Student));
    return 0;
}