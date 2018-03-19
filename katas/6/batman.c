#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    scanf("%d%d", &X0, &Y0);
    
    // ranges
    int Xi = 0;
    int Xf = W;
    int Yi = 0;
    int Yf = H;
    
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        if (!strcmp(bombDir, "U")) {
            Yf = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
        }
        else if (!strcmp(bombDir, "UR")) {
            Yf = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
            
            Xi = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        else if (!strcmp(bombDir, "R")) {
            Xi = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        else if (!strcmp(bombDir, "DR")) {
            Yi = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
            
            Xi = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        else if (!strcmp(bombDir, "D")) {
            Yi = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
        }
        if (!strcmp(bombDir, "DL")) {
            Yi = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
            
            Xf = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        if (!strcmp(bombDir, "L")) {
            Xf = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        if (!strcmp(bombDir, "UL")) {
            Yf = Y0;
            Y0 = Yi + (Yf - Yi) / 2;
            
            Xf = X0;
            X0 = Xi + (Xf - Xi) / 2;
        }
        
        // the location of the next window Batman should jump to.
        printf("%d %d\n", X0, Y0);
    }

    return 0;
}
