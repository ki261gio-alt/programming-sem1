#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100000

int main(void) {
    double x, eps;

    printf("=== Calculation of sh(x) via infinite series (Variant 6) ===\n");
    printf("Enter argument X and accuracy eps (e.g. 1.5 0.00001): ");

    if (scanf("%lf %lf", &x, &eps) != 2) {
        printf("Error: Invalid input data!\n");
        return 1;
    }

    if (eps <= 0) {
        printf("Error: Accuracy eps must be greater than 0!\n");
        return 1;
    }

    // First term for n = 0: a_0 = x
    double a_n = x;
    double sum = a_n;
    int n = 0;
    int iter_count = 1;

    // Series accumulation with recurrence relation
    while (fabs(a_n) >= eps) {
        if (iter_count >= MAX_ITER) {
            printf("\nWarning: Iteration limit reached (%d)! Series diverges or eps is too small.\n", MAX_ITER);
            break;
        }

        n++;
        // Recurrence ratio: R(n, X) = X^2 / (2n * (2n + 1))
        double R = (x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        a_n *= R;
        sum += a_n;
        iter_count++;
    }

    // Exact value via standard library function sinh() from <math.h>
    double exact_val = sinh(x);
    double abs_err = fabs(sum - exact_val);
    double rel_err = (exact_val != 0) ? (abs_err / fabs(exact_val)) * 100.0 : 0.0;

    printf("\n=== Calculation Results ===\n");
    printf("Argument X:          %.6lf\n", x);
    printf("Specified eps:       %.8lf\n", eps);
    printf("Calculated Sum:      %.10lf\n", sum);
    printf("Exact Value (sinh):  %.10lf\n", exact_val);
    printf("Absolute Error:      %.10e\n", abs_err);
    printf("Relative Error:      %.6lf %%\n", rel_err);
    printf("Iterations Count:    %d\n", iter_count);

    return 0;
}