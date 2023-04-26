#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>

#define N 1000 // número de decimales a sumar

int main()
{
    int n = 10000000; // número de iteraciones
    int i, j;
    double x, sum = 0.0;
    mpf_t term, pi;
    mpf_init(term);
    mpf_init(pi);

    #pragma omp parallel for private(j, x, term) reduction(+:sum)
    for (i = 0; i < n; i++) {
        mpf_set_ui(term, 1);
        for (j = 1; j <= N; j++) {
            x = (double)j / (double)(i * N + j);
            mpf_mul_d(term, term, x);
        }
        mpf_div_ui(term, term, i * N + 1);
        sum += mpf_get_d(term);
    }

    mpf_set_d(pi, sum * 2.0);
    gmp_printf("%.1000Ff\n", pi);

    mpf_clear(term);
    mpf_clear(pi);
    return 0;
}
