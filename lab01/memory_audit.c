#include <stdio.h>

int main(void) {
    // 1. Визначення розмірів типів даних у байтах за допомогою оператора sizeof (%zu)
    printf("=== Memory Audit: Data Type Sizes ===\n");
    printf("sizeof(char):      = %zu byte(s)\n", sizeof(char));
    printf("sizeof(short):     = %zu byte(s)\n", sizeof(short));
    printf("sizeof(int):       = %zu byte(s)\n", sizeof(int));
    printf("sizeof(long):      = %zu byte(s)\n", sizeof(long));
    printf("sizeof(long long): = %zu byte(s)\n", sizeof(long long));
    printf("sizeof(float):     = %zu byte(s)\n", sizeof(float));
    printf("sizeof(double):    = %zu byte(s)\n", sizeof(double));
    printf("sizeof(void*):     = %zu byte(s)\n", sizeof(void*));
    printf("\n");

    // 2. Демонстрація явищ переповнення (Integer Overflow)
    unsigned char byte_test = 255;
    printf("=== Integer Overflow Demonstration ===\n");
    printf("Initial byte_test: decimal = %u, hex = 0x%02X\n", byte_test, byte_test);

    // Додаємо 1 для викликання переповнення
    printf("After byte_test + 1: decimal = %u, hex = 0x%02X\n", byte_test, byte_test);
    return 0;
}