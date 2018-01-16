#include <stdio.h>

const int MAX = 2147483647;

int main() {
    int a = 4;
    float f = 7.5;
    int j;
    int *p;

    int b = a + (int)f;
    float c = a * f;
    long int d = (long)MAX * MAX; 

    p = &a;
    *p = 7;
    p++;
    *p = 8;

    printf("a = %d, b = %d, j = %d, d = %ld\n", a, b, j, d);
    printf("c = %f, f = %f\n", c, f);

    int arr[5] = {0};
    *(arr + 1) = 20;
    
    p = arr;
    for (int i = 0; i < 5; i++) {
        *p = 67;
        p++;
    }

    printf("arr[1] = %d\n", arr[1]);
    return 0;
}
