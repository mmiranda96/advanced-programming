#include <stdio.h>
#include <omp.h>

#define SIZE 200000
int main()
{
    int a[SIZE];
    int b[SIZE];
    int c[SIZE];
    int chunk = 1000;

    for (int i = 0; i  < SIZE; i++) {
        a[i] = i;
        b[i] = 2 * i;
    }

    #pragma omp parallel shared(a, b, c, chunk)
    {
        #pragma omp for schedule(dynamic, chunk) nowait
        for (int i = 0; i < SIZE; i++) {
            c[i] = a[i] + b[i];
            printf("c[%d] = %d\n", i, c [i]);
        }
    }
}
