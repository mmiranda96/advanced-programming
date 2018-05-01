#include <stdlib.h>
#include <stdio.h>
#include "partitions.h"

char * partition(int *a, int n)
{
    // Calculate the sum of A
    long sum = 0; // Type long to prevent overflows
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    char *result = (char *) malloc(sizeof(char) * n);
    result[0] = '1';
    // Iterate through all k's (except 1)
    for (int i = 1; i < n ; i++) {
        int k = i + 1;
        if (sum % k != 0) {
            result[i] = '0';
            continue;
        }

        long sizeOfPartitions = sum / k;

        int numberOfPartitions = 1;
        long temp = 0;
        for (int j = 0; j < n; j++) {
            if (temp > sizeOfPartitions) { // Surpass the temp sum
                break;
            }

            if (temp == sizeOfPartitions) {
                numberOfPartitions++;
                temp = 0;
            }
            temp += a[j];
        }

        // Array finished and temp sum is not complete or number of partitions is not k
        if (temp != sizeOfPartitions || numberOfPartitions != k) {
            result[i] = '0';
        }
        else {
            result[i] = '1';
        }
    }

    return result;
}