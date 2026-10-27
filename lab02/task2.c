#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100000

int main(void) {
    double x, eps;

    printf("=== Обчислення sh(x) за допомогою нескінченного ряду (Варіант 6) ===\n");
    printf("Введіть аргумент X та точність eps (наприклад, 1.5 0.00001): ");

    if (scanf("%lf %lf", &x, &eps) != 2) {
        printf("Помилка: Некоректне введення даних!\n");
        return 1;
    }

    if (eps <= 0) {
        printf("Помилка: Точність eps повинна бути більшою за 0!\n");
        return 1;
    }

    // Перший член ряду для n = 0: a_0 = x
    double a_n = x;
    double sum = a_n;
    int n = 0;
    int iter_count = 1;

    // Накопичення суми ряду з рекурентним співвідношенням
    while (fabs(a_n) >= eps) {
        if (iter_count >= MAX_ITER) {
            printf("\nПопередження: Досягнуто ліміт ітерацій (%d)! Ряд розбігається або eps занадто мала.\n", MAX_ITER);
            break;
        }

        n++;
        // Рекурентне співвідношення: R(n, X) = X^2 / (2n * (2n + 1))
        double R = (x * x) / ((2.0 * n) * (2.0 * n + 1.0));
        a_n *= R;
        sum += a_n;
        iter_count++;
    }

    // Точне значення через стандартну бібліотечну функцію sinh() з <math.h>
    double exact_val = sinh(x);
    double abs_err = fabs(sum - exact_val);
    double rel_err = (exact_val != 0) ? (abs_err / fabs(exact_val)) * 100.0 : 0.0;

    printf("\n=== Результати обчислення ===\n");
    printf("Аргумент X:                  %.6lf\n", x);
    printf("Задана точність eps:         %.8lf\n", eps);
    printf("Обчислена сума ряду:         %.10lf\n", sum);
    printf("Еталонне значення (sinh):   %.10lf\n", exact_val);
    printf("Абсолютна похибка:           %.10e\n", abs_err);
    printf("Відносна похибка:            %.6lf %%\n", rel_err);
    printf("Кількість ітерацій:         %d\n", iter_count);

    return 0;
}