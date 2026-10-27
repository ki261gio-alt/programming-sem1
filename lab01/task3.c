#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    double f, c;

    printf("=== Capacitive Reactance Calculation (Variant 6) ===\n");
    printf("Enter frequency f (Hz) and capacitance C (F): ");

    // Валідація зчитування даних
    if (scanf("%lf %lf", &f, &c) != 2) {
        printf("Error: Invalid input data!\n");
        return 1;
    }

    // Захист від від'ємних значень та ділення на нуль
    if (f <= 0 || c <= 0) {
        printf("Error: Frequency (f) and Capacitance (C) must be greater than 0!\n");
        return 1;
    }

    // Обчислення за формулою Xc = 1 / (2 * pi * f * C)
    double Xc = 1.0 / (2.0 * M_PI * f * c);

    printf("\n=== Calculation Results ===\n");
    printf("Frequency (f):     %.2lf Hz\n", f);
    printf("Capacitance (C):   %.10lf F\n", c);
    printf("Reactance (Xc):    %.3lf Ohm\n", Xc);

    return 0;
}