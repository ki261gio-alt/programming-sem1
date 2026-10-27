#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double x_start, x_end, dx;

    printf("=== Tabulation of piecewise function (Variant 6) ===\n");
    printf("Enter Xstart, Xend, and dX (e.g. -2 4 0.5): ");

    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        printf("Error: Invalid input data!\n");
        return 1;
    }

    // Input parameters validation
    if (x_start >= x_end || dx <= 0) {
        printf("Error: Expected Xstart < Xend and dX > 0!\n");
        return 1;
    }

    printf("\n+------------+------------+\n");
    printf("|     X      |    Y(X)    |\n");
    printf("+------------+------------+\n");

    // Loop with floating-point tolerance check
    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        if (x < 0) {
            // Y = 1 / (1 + X^2)
            double denom = 1.0 + x * x;
            if (fabs(denom) < 1e-9) {
                printf("| %10.4lf | [Undefined] |\n", x);
            } else {
                double y = 1.0 / denom;
                printf("| %10.4lf | %10.4lf |\n", x, y);
            }
        } else if (x <= 2.0) {
            // Y = 1 - 2*X
            double y = 1.0 - 2.0 * x;
            printf("| %10.4lf | %10.4lf |\n", x, y);
        } else {
            // Y = 3 * sqrt(X)
            if (x < 0) {
                printf("| %10.4lf | [Undefined] |\n", x);
            } else {
                double y = 3.0 * sqrt(x);
                printf("| %10.4lf | %10.4lf |\n", x, y);
            }
        }
    }

    printf("+------------+------------+\n");
    return 0;
}