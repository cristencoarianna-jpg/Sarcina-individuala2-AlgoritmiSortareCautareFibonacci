#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

// Funcție iterativă pentru Fibonacci folosind GMP
void fibonacci(mpz_t result, unsigned long n) {
    mpz_t a, b, temp;
    mpz_init_set_ui(a, 0);   // fib(0) = 0
    mpz_init_set_ui(b, 1);   // fib(1) = 1
    mpz_init(temp);

    if (n == 0) {
        mpz_set(result, a);
    } else if (n == 1) {
        mpz_set(result, b);
    } else {
        for (unsigned long i = 2; i <= n; i++) {
            mpz_add(temp, a, b); // temp = a + b
            mpz_set(a, b);       // a = b
            mpz_set(b, temp);    // b = temp
        }
        mpz_set(result, b);
    }

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(temp);
}

int main() {
    unsigned long N;
    printf("Introdu N: ");
    scanf("%lu", &N);

    mpz_t result;
    mpz_init(result);

    clock_t start = clock();
    fibonacci(result, N);
    clock_t end = clock();

    gmp_printf("Fib(%lu) = %Zd\n", N, result);
    printf("Timp executie: %f secunde\n", (double)(end-start)/CLOCKS_PER_SEC);

    mpz_clear(result);
    return 0;
}