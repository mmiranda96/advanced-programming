#include <stdio.h>
#include <stdlib.h>

float needForSpeed(int, int, int*, int*);

int main()
{
    int numberOfSegments;
    int totalTime;

    int *distances;
    int *speeds;

    scanf("%d %d", &numberOfSegments, &totalTime);

    distances = (int *)malloc(sizeof(int) * numberOfSegments);
    speeds = (int *)malloc(sizeof(int) * numberOfSegments);

    for (int i = 0; i < numberOfSegments; i++)
    {
        scanf("%d %d", &distances[i], &speeds[i]);
    }

    return 0;
}

float needForSpeed(int numberOfSegments, int totalTime, int *distances, int *speeds)
{
    // Do math and witchcraft to solve the problem
    return 0;
}