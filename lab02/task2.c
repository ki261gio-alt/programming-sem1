#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100000

int main(void) {
    double x, eps;

    printf("=== Calculation of sh(x) via infinite series (Variant 6) ===\n");
    printf("Enter argument X: ");
    if (scanf("%lf", &x) != 1) {
        printf("Error reading argument X.\n");
        return 1;
    }

    printf("Enter precision eps (e.g. 0.00001): ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("Error: precision eps must be positive.\n");
        return 1;
    }

    double term = x;
    double sum = term;
    int n = 1;
    int iterations = 1;

    while (fabs(term) >= eps) {
        if (iterations >= MAX_ITERATIONS) {
            printf("\n[WARNING] Exceeded iteration limit (%d)!\n", MAX_ITERATIONS);
            break;
        }

        double r = (x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        term *= r;
        sum += term;

        n++;
        iterations++;
    }

    double exact_value = sinh(x);
    double abs_error = fabs(sum - exact_value);

    printf("\n=== Results ===\n");
    printf("Argument X:          %lf\n", x);
    printf("Precision eps:       %.1e\n", eps);
    printf("Calculated sum:      %.10lf\n", sum);
    printf("Reference sinh(x):   %.10lf\n", exact_value);
    printf("Absolute error:      %.1e\n", abs_error);
    printf("Iterations count:    %d\n", iterations);

    return 0;
}