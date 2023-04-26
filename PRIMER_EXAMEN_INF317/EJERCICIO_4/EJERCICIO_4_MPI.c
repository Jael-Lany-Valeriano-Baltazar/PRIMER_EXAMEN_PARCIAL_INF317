#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a = (1 + sqrt(5)) / 2.0;
    double b = (1 - sqrt(5)) / 2.0;

   
    int n_per_proc = 1000 / size;
    int start_index = rank * n_per_proc;
    int end_index = start_index + n_per_proc;
    double fib_n = 0.0;
    double partial_sum = 0.0;
    for (int i = start_index; i < end_index; i++) {
        fib_n = ((pow(a, i) - pow(b, i)) / sqrt(5));
        partial_sum += fib_n;
    }

    double result = 0.0;
    MPI_Reduce(&partial_sum, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < 1000; i++) {
            fib_n = ((pow(a, i) - pow(b, i)) / sqrt(5));
            printf("%.0f ", fib_n);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}


//Compilar:
//  mpicc EJERCICIO_4_MPI.c -o e4_MPI -lm