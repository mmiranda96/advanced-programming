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
        MAP_FILE | MAP_PRIVATE,
        fd,
        0);
    close(fd);
    
    printf("Student at 5:\n");
    printf("ID: %d\n", pAvanzada[5].Id);
    printf("firstName: %s\n", pAvanzada[5].firstName);
    printf("lastName: %s\n", pAvanzada[5].lastName);
    printf("semester: %s\n", pAvanzada[5].semester);

    munmap(pAvanzada, 10 * sizeof(Student));
    return 0;
}