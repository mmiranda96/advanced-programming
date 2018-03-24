#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BOOST_DISTANCE 9000
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    int usedBoost = 0;
    // game loop
    while (1)
    {
        int x;
        int y;
        int nextCheckpointX;     // x position of the next check point
        int nextCheckpointY;     // y position of the next check point
        int nextCheckpointDist;  // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        int thrust = nextCheckpointAngle > 90 || nextCheckpointAngle < -90 ? 0 : 100;

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        if (nextCheckpointAngle == 0 && !usedBoost && nextCheckpointDist > BOOST_DISTANCE)
        {
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            usedBoost = 1;
        }
        else
        {
            printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
        }
    }

    return 0;
}
